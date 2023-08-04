// gcc hello_python.c $(python3-config --includes --embed) $(python3-config --libs --embed) $(python3-config --ldflags --embed) -v &> gcc.log

// ../emsdk/emsdk activate latest
// source "/home/pradeep/projects/emsdk/emsdk_env.sh"
// export PATH=/home/pradeep/projects/cpython/builddir/build:$PATH
// gcc hello_python.c -I/home/pradeep/projects/cpython/Include -I/home/pradeep/projects/cpython/builddir/build -L/home/pradeep/projects/cpython/builddir/build $(python-config --libs --embed) $(python-config --ldflags --embed) -v &> gcc.log
// gcc hello_python.c -I/home/pradeep/projects/cpython/Include -I/home/pradeep/projects/cpython/builddir/build -L/home/pradeep/projects/cpython/builddir/build $(python-config --libs --embed) $(python-config --ldflags --embed) $(python-config --cflags) -v &> gcc.log
// gcc hello_python.c -I/home/pradeep/projects/cpython/Include -I/home/pradeep/projects/cpython/builddir/build -L/home/pradeep/projects/cpython/builddir/build $(python-config --libs --embed) $(python-config --ldflags --embed) /usr/lib/gcc/x86_64-linux-gnu/11/libgcc.a $(python-config --cflags) /usr/lib/x86_64-linux-gnu/libc.a -static  -v &> gcc.log
// gcc hello_python.c -I/home/pradeep/projects/cpython/Include -I/home/pradeep/projects/cpython/builddir/build /home/pradeep/projects/cpython/builddir/build/libpython3.13.a -ldl -lm -v -static &> gcc.log
// gcc hello_python.c -L/home/pradeep/projects/cpython/builddir/build $(python-config --ldflags --embed) $(python-config --cflags --embed) -I/home/pradeep/projects/cpython/Include -I/home/pradeep/projects/cpython/builddir/build /lib/x86_64-linux-gnu/libm.so.6  /lib/x86_64-linux-gnu/libc.so.6 /lib64/ld-linux-x86-64.so.2 -ldl -lm -v  &> gcc.log

// ../emsdk/emsdk activate latest
// source "/home/pradeep/projects/emsdk/emsdk_env.sh"
// export PATH=/home/pradeep/projects/cpython/builddir/emscripten-browser:$PATH
// gcc hello_python.c -I/home/pradeep/projects/cpython/Include -I/home/pradeep/projects/cpython/builddir/emscripten-browser -L/home/pradeep/projects/cpython/builddir/emscripten-browser $(python-config --libs --embed) $(python-config --cflags) $(python-config --ldflags --embed) -v &> gcc.log
// emcc hello_python.c /home/pradeep/projects/cpython/builddir/emscripten-browser/Modules/_decimal/libmpdec/libmpdec.a /home/pradeep/projects/cpython/builddir/emscripten-browser/Modules/expat/libexpat.a /home/pradeep/projects/cpython/builddir/emscripten-browser/Modules/_hacl/libHacl_Hash_SHA2.a  -I/home/pradeep/projects/cpython/Include -I/home/pradeep/projects/cpython/builddir/emscripten-browser -L/home/pradeep/projects/cpython/builddir/emscripten-browser  $(python-config --cflags) -lz -lbz2 /home/pradeep/projects/emsdk/upstream/emscripten/cache/sysroot/lib/wasm32-emscripten/libsqlite3.a $(python-config --ldflags --embed)  -v -Wl,-error-limit=200 &> emcc.log
#include <stdio.h>
#include <Python.h>

int main() {
  Py_Initialize();
  PyRun_SimpleString("print (\"Hello world from python\")");
  return 0;
}
