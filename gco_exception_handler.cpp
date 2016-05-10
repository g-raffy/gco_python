#include "Python.h"
#include "GCoptimization.h"
#include <exception>
#include <string>

using namespace std;

extern PyObject *gcerror; // a python exception object that represents the graph cut exception in python

/**
	\brief	this function translates graph cut exceptions into python exceptions.
	
	It uses the mechanism described in http://stackoverflow.com/questions/10684983/handling-custom-c-exceptions-in-cython
*/
void handle_gco_exception()
{
	try
	{
		throw;
	}
	catch (GCException& e)
	{
		PyErr_SetString(gcerror, e.message);
	}
	catch (const std::exception& e)
	{
		PyErr_SetString(PyExc_RuntimeError, e.what() );
	}
}
