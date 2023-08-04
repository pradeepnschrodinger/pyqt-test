// gcc hello_python.c $(python3-config --includes --embed) $(python3-config --libs --embed) $(python3-config --ldflags --embed) -v &> gcc.log

#include <stdio.h>
#include <Python.h>

int main() {
  Py_Initialize();
  PyRun_SimpleString("print (\"Hello world from python\")");
  return 0;
}
