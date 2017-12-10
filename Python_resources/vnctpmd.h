
#include <stdio.h>
#include <string>
#include <queue>

// Boost
#include <boost/python/dict.hpp>
#include <boost/python.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/any.hpp>

// Api
#include "ThostFtdcMdApi.h"

// 全名空间
using namespace std;
using namespace boost::python;
using namespace boost;

// 常量
#define ONFRONTCONNECTED 1
#define ONFRONTDISCONNECTED 2
#define ONHEARTBEATWARNING 3
#define ONRSPERROR 4
#define ONRSPUSERLOGIN 5
#define ONRSPUSERLOGOUT 6
#define ONRSPSUBMARKETDATA 7
#define ONRSPUNSUBMARKETDATA 8
#define ONRTNDEPTHMARKETDATA 9
#define EXIT 0

#define _DEBUG_		1	// print some debug message

#define DEBUG_PRINT \
		#if _DEBUG_ \
			printf("%s() is invoked!\n", __FUNCTION__); \
		#endif
//------------------------------------------------------
// API中的部分组件
//------------------------------------------------------

// GIL全局锁，用于帮助C++线程获得GIL锁，从而防止python崩溃
class PyLock
{
private:
	PyGILState_STATE gil_state;

public:
	PyLock() {
		gil_state = PyGILState_Ensure();
	}

	~PyLock() {
		PyGILState_Release(gil_state);
	}
};

// 任务结构体
struct Task 
{
	int task_name;
	any task_data;
	any task_error;
	int task_id;
	bool task_last;
};

// 线程安全的队列
template<typename Data>

class ConcurrentQueue 
{
private:
	queue<Data> the_queue;						// 标准库队列
	mutex the_mutex;							// boost智能互斥锁
	condition_variable the_condition_variable;	// boost条件变量

public:
	void push(Data const& data) {
		mutex::scoped_lock lock(the_mutex);		// 获取智能锁
		the_queue.push(data);
		lock.unlock(the_mutex);
		the_condition_variable.notify_one();	// 通知正在阻塞等待的线程
	}

	bool empty() const {
		mutex::scoped_lock lock(the_mutex);
		return the_queue.empty();
	}

	Data wait_and_pop() {
		mutex::scoped_lock lock(the_mutex);

		while (the_queue.empty()) {
			the_condition_variable.wait(lock);
		}

		Data value = the_queue.front();
		the_queue.pop();
		return value;
	}
};


void getInt(dict d, string key, int* value);

void getDouble(dict d, string key, double* value);

void getChar(dict d, string key, char* value);

void getStr(dict d, string key, char* value);


// API的继承实现
class MdApi : public CThostFtdcMdSpi
{
private:
	CThostFtdcMdApi* api;
	thread *task_thread;
	ConcurrentQueue<Task> task_queue;

public:
	MdApi() {
		function0<void> f = boost::bind(&MdApi::processTask, this);
		thread t(f);
		this->task_thread = &t;
	};

	~MdApi() {

	};

	//virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	//------------------------------------------------------
	// task: 任务
	//------------------------------------------------------
	void processTask();

	void processFrontConnected(Task task);

	void processRspUserLogin(Task task);

	//------------------------------------------------------
	//------------------------------------------------------
	virtual void onRspUserLogin(dict data, dict error, int id, bool last) { }

	//------------------------------------------------------
	// req: 主动函数的请求字典
	//------------------------------------------------------
	void createFtdcMdApi(string pszFlowPath = "");

	void release();

	void init();

	void join();

	void exit();

	string getTradingDay();

	void registerFront(string pszFrontAddress);

	int reqUserLogin(dict req, int nRequestID);
};
