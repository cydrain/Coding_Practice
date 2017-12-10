#include "boost/python.hpp"
#include "student.cpp"

using namespace boost::python;

BOOST_PYTHON_MODULE(example) {
	class_<student>("student")
	.def("setname", &student::setname)
	.def("getname", &student::getname)
	.def("setage", &student::setage)
	.def("getage", &student::getage)
	//.add_property("name_", &student::getname, &student::setname)
	//.add_property("age_", &student::getage, &student::setage)
    .def_readwrite("name_", &student::name_)
    .def_readwrite("age_", &student::age_)
	;
}
