#include "vnctpmd.h"

//-----------------------------------------------------------------------------
// 从python对象到C++类型转换用的函数
//-----------------------------------------------------------------------------
void getInt(dict d, string key, int* value)
{
	if (d.has_key(key)) {
		object o = d[key];
		extract<int> x(o);
		if (x.check()) {
			*value = x();
		}
	}
}

void getDouble(dict d, string key, double* value)
{
	if (d.has_key(key)) {
		object o = d[key];
		extract<double> x(o);
		if (x.check()) {
			*value = x();
		}
	}
}

void getStr(dict d, string key, char* value)
{
	if (d.has_key(key)) {
		object o = d[key];
		extract<string> x(o);
		if (x.check()) {
			string s = x();
			const char* buffer = s.c_str();
#ifdef _MSC_VER // WIN32
			strcpy(value, strlen(buffer)+1, buffer);
#elif _GNUC_
			strncpy(value, buffer, strlen(buffer)+1);
#endif
		}
	}
}

void getChar(dict d, string key, char* value)
{
	if (d.has_key(key)) {
		object o = d[key];
		extract<string> x(o);
		if (x.check()) {
			string s = x();
			const char* buffer = s.c_str();
			*value = *buffer;
		}
	}
}

//-----------------------------------------------------------------------------
// C++的回调函数将数据保存到队列中
//-----------------------------------------------------------------------------

void MdApi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	DEBUG_PRINT
	Task task = Task();
	task.task_name = ONRSPUSERLOGIN;

	if (pRspUserLogin) {
		task.task_data = *pRspUserLogin;
	} else {
		CThostFtdcRspUserLoginField empty_data = CThostFtdcRspUserLoginField();
		memset(&empty_data, 0, sizeof(CThostFtdcRspUserLoginField));
		task.task_data = empty_data;
	}

	if (pRspInfo) {
		task.task_error = *pRspInfo;
	} else {
		CThostFtdcRspInfoField empty_error = CThostFtdcRspInfoField();
		memset(&empty_error, 0, sizeof(CThostFtdcRspInfoField));
		task.task_error = empty_error;
	}

	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
}

//-----------------------------------------------------------------------------
// 工作线程从队列中取出数据，转化为python对象后，进行推送
//-----------------------------------------------------------------------------

void MdApi::processTask()
{
	while (1) {
		Task task = this->task_queue.wait_and_pop();

		switch (task.task_name) {
			case ONRSPUSERLOGIN:
				this->processRspUserLogin(task);
				break;
			default:
				break;
		}
	}
}

void MdApi::processRspUserLogin(Task task)
{
	PyLock lock;
	CThostFtdcRspUserLoginField task_data = 
									any_cast<CThostFtdcRspUserLoginField>(task.task_data);
	dict data;
	data["TradingDay"]	= task_data.TradingDay;
	data["LoginTime"]	= task_data.LoginTime;
	data["BrokerID"]	= task_data.BrokerID;
	data["UserID"]		= task_data.UserID;
	data["SystemName"]	= task_data.SystemName;
	data["FrontID"]		= task_data.FrontID;
	data["SessionID"]	= task_data.SessionID;
	data["MaxOrderRef"]	= task_data.MaxOrderRef;
	data["SHFETime"]	= task_data.SHFETime;
	data["DCETime"]		= task_data.DCETime;
	data["CZCETime"]	= task_data.CZCETime;
	data["FFEXTime"]	= task_data.FFEXTime;
	data["INETime"]		= task_data.INETime;

	CThostFtdcRspInfoField task_error = any_cast<CThostFtdcRspInfoField>(task.task_error);
	dict error;
	error["ErrorID"]	= task_error.ErrorID;
	error["ErrorMsg"]	= task_error.ErrorMsg;

	this->onRspUserLogin(data, error, task.task_id, task.task_last);
}

//-----------------------------------------------------------------------------
// 主动函数
//-----------------------------------------------------------------------------

void MdApi::createFtdcMdApi(string pszFlowPath)
{
	this->api = CThostFtdcMdApi::CreateFtdcMdApi(pszFlowPath.c_str());
	this->api->RegisterSpi(this);
}

void MdApi::release()
{
	this->api->Release();
}

void MdApi::init()
{
	this->api->Init();
}

int MdApi::join()
{
	int i = this->api->Join();
	return i;
}

string MdApi::getTradingDay()
{
	string day = this->api->getTradingDay();
	return day;
}

void MdApi::registerFront(string pszFrontAddress)
{
	this->api->RegisterFront(pszFrontAddress.c_str());
}

int MdApi::reqUserLogin(dict req, int nRequestID)
{
	CThostFtdcReqUserLoginField myreq = CThostFtdcReqUserLoginField();
	memset(&myreq, 0, sizeof(CThostFtdcReqUserLoginField));
	getStr(req, "TradingDay",			myreq.TradingDay);
	getStr(req, "BrokerID", 			myreq.BrokerID);
	getStr(req, "UserID",				myreq.UserID);
	getStr(req, "Password",				myreq.Password);
	getStr(req, "UserProductInfo",		myreq.UserProductInfo);
	getStr(req, "InterfaceProductInfo",	myreq.InterfaceProductInfo);
	getStr(req, "ProtocolInfo",			myreq.ProtocolInfo);
	getStr(req, "MacAddress",			myreq.MacAddress);
	getStr(req, "OneTimePassword",		myreq.OneTimePassword);
	getStr(req, "ClientIPAddress",		myreq.ClientIPAddress);

	int i = this->api->ReqUserLogin(&myreq, nRequestID);
	return i;
}

//-----------------------------------------------------------------------------
// Boost.Python 封装
//-----------------------------------------------------------------------------

struct MdApiWrap : MdApi, wrapper<MdApi>
{
	virtual void onRspUserLogin(dict data, dict error, int id, bool last)
	{
		try {
			this->get_override("onRspUserLogin")(data, error, id, last);
		}
		catch (error_already_set const &) {
			PyErr_Print();
		}
	}
};


BOOST_PYTHON_MODULE(vnctpmd)
{
	PyEval_InitThreads();	// 导入时运行，保证先创建GIL

	class_<MdApiWrap, boost::noncopyable>("MdApi")
		.def("createFtdcMdApi",			&MdApiWrap::createFtdcMdApi)
		.def("release",					&MdApiWrap::release)
		.def("init",					&MdApiWrap::init)
		.def("join",					&MdApiWrap::join)
		.def("getTradingDay",			&MdApiWrap::getTradingDay)
		.def("registerFront",			&MdApiWrap::registerFront)
		.def("reqUserLogin",			&MdApiWrap::reqUserLogin)

		.def("onRspUserLogin",			pure_virtual(&MdApiWrap::onRspUserLogin))
		;
}
