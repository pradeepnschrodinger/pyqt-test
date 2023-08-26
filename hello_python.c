// gcc hello_python.c $(python3-config --includes --embed) $(python3-config --libs --embed) $(python3-config --ldflags --embed) -v &> gcc.log
// gcc hello_python.c -I/home/pradeep/projects/cpython/Include -I/home/pradeep/projects/cpython/builddir/build $(python-config --cflags --embed) $(python-config --ldflags --embed) $(python-config --libs --embed) $(python-config --includes --embed) &> gcc.log

// /opt/emsdk/emsdk activate latest
// source "/opt/emsdk/emsdk_env.sh"
// export PATH=/home/pradeep/projects/cpython/builddir/build:$PATH

// emcc hello_python.c $(python3-config --includes --embed) $(python3-config --libs --embed)
// why can't emcc (wasm-ld) find -lpython3.13?
// emcc hello_python.c $(python3-config --includes --embed) -L/home/pradeep/projects/cpython/builddir/emscripten-node-dl $(python3-config --libs --embed)
// emcc hello_python.c $(python3-config --includes --embed) -L/home/pradeep/projects/cpython/builddir/emscripten-node-dl $(python3-config --libs --embed) /home/pradeep/projects/cpython/builddir/emscripten-node-dl/Modules/_decimal/libmpdec/libmpdec.a ../cpython/builddir/emscripten-node-dl/Modules/_hacl/libHacl_Hash_SHA2.a ../cpython/builddir/emscripten-node-dl/Modules/expat/libexpat.a /opt/emsdk/upstream/emscripten/cache/sysroot/lib/wasm32-emscripten/libsqlite3-mt.a -lz -lbz2 -v &> emcc.log

// support with noderaw filesystem 
// emcc hello_python.c $(python3-config --includes --embed) -L/home/pradeep/projects/cpython/builddir/emscripten-node-dl $(python3-config --libs --embed) /home/pradeep/projects/cpython/builddir/emscripten-node-dl/Modules/_decimal/libmpdec/libmpdec.a ../cpython/builddir/emscripten-node-dl/Modules/_hacl/libHacl_Hash_SHA2.a ../cpython/builddir/emscripten-node-dl/Modules/expat/libexpat.a /opt/emsdk/upstream/emscripten/cache/sysroot/lib/wasm32-emscripten/libsqlite3-mt.a -lz -lbz2 -v -static -Wl,-static -lnodefs.js -lnoderawfs.js &> emcc.log

// support with browser?
// emcc hello_python.c --pre-js ModuleSettings.js -o a.html $(python3-config --includes --embed) -L/home/pradeep/projects/cpython/builddir/emscripten-node-dl $(python3-config --libs --embed) /home/pradeep/projects/cpython/builddir/emscripten-node-dl/Modules/_decimal/libmpdec/libmpdec.a ../cpython/builddir/emscripten-node-dl/Modules/_hacl/libHacl_Hash_SHA2.a ../cpython/builddir/emscripten-node-dl/Modules/expat/libexpat.a /opt/emsdk/upstream/emscripten/cache/sysroot/lib/wasm32-emscripten/libsqlite3-mt.a -lz -lbz2 -v -static -Wl,-static  -fdeclspec &> emcc.log

#include <stdio.h>
#include <Python.h>
extern char **environ;

/*
NOTE (pradeep)
Py_NoSiteFlag (see https://docs.python.org/3/c-api/init.html):
Disable the import of the module site and the site-dependent manipulations of sys.path that it entails. Also disable these manipulations if site is explicitly imported later (call site.main() if you want them to be triggered).
*/
// extern __declspec(dllimport) int Py_NoSiteFlag;

int main(int argc, char **argv, char **envp) {
  char **s = environ;

  for (; *s; s++) {
    printf("%s\n", *s);
  }

  /*
    NOTE (pradeep):
    I'm using this flag to avoid an error where the python runtime tries to look into encodings library, but is not able to find it since we're running it in a browser environment.
    Based on suggestion from https://stackoverflow.com/questions/39539089/what-files-are-required-for-py-initialize-to-run
  */
  // Py_NoSiteFlag = 1; /* Suppress 'import site' errors */
  // Py_InitializeEx(0); // skips initialization registration of signal handlers, which might be useful when Python is embedded.
  Py_Initialize();

  PyRun_SimpleString("print (\"Hello world from python\")");
  return 0;
}
