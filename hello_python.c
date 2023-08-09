// gcc hello_python.c $(python3-config --includes --embed) $(python3-config --libs --embed) $(python3-config --ldflags --embed) -v &> gcc.log
// gcc hello_python.c -I/home/pradeep/projects/cpython/Include -I/home/pradeep/projects/cpython/builddir/build $(python-config --cflags --embed) $(python-config --ldflags --embed) $(python-config --libs --embed) $(python-config --includes --embed) &> gcc.log

// ../emsdk/emsdk activate latest
// source "/home/pradeep/projects/emsdk/emsdk_env.sh"
// export PATH=/home/pradeep/projects/cpython/builddir/build:$PATH

// emcc hello_python.c $(python3-config --includes --embed) $(python3-config --libs --embed)
// why can't emcc (wasm-ld) find -lpython3.13?
// emcc hello_python.c $(python3-config --includes --embed) -L/home/pradeep/projects/cpython/builddir/emscripten-node-dl $(python3-config --libs --embed)
// emcc hello_python.c $(python3-config --includes --embed) -L/home/pradeep/projects/cpython/builddir/emscripten-node-dl $(python3-config --libs --embed) /home/pradeep/projects/cpython/builddir/emscripten-node-dl/Modules/_decimal/libmpdec/libmpdec.a ../cpython/builddir/emscripten-node-dl/Modules/_hacl/libHacl_Hash_SHA2.a ../cpython/builddir/emscripten-node-dl/Modules/expat/libexpat.a ../emsdk/upstream/emscripten/cache/sysroot/lib/wasm32-emscripten/libsqlite3-mt.a -lz -lbz2 -v &> emcc.log
// emcc hello_python.c $(python3-config --includes --embed) -L/home/pradeep/projects/cpython/builddir/emscripten-node-dl $(python3-config --libs --embed) /home/pradeep/projects/cpython/builddir/emscripten-node-dl/Modules/_decimal/libmpdec/libmpdec.a ../cpython/builddir/emscripten-node-dl/Modules/_hacl/libHacl_Hash_SHA2.a ../cpython/builddir/emscripten-node-dl/Modules/expat/libexpat.a ../emsdk/upstream/emscripten/cache/sysroot/lib/wasm32-emscripten/libsqlite3-mt.a -lz -lbz2 -v -static -Wl,-static -lnodefs.js -lnoderawfs.js
#include <stdio.h>
#include <Python.h>
extern char **environ;

int main(int argc, char **argv, char **envp) {
  char **s = environ;

  for (; *s; s++) {
    printf("%s\n", *s);
  }
  Py_Initialize();
  PyRun_SimpleString("print (\"Hello world from python\")");
  return 0;
}
