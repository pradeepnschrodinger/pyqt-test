# emcc python_arch.c --pre-js ModuleSettings.js -o a.html $(python3-config --includes --embed) -L/home/pradeep/projects/cpython/builddir/emscripten-node-dl $(python3-config --libs --embed) /home/pradeep/projects/cpython/builddir/emscripten-node-dl/Modules/_decimal/libmpdec/libmpdec.a ../cpython/builddir/emscripten-node-dl/Modules/_hacl/libHacl_Hash_SHA2.a ../cpython/builddir/emscripten-node-dl/Modules/expat/libexpat.a /opt/emsdk/upstream/emscripten/cache/sysroot/lib/wasm32-emscripten/libsqlite3-mt.a -lz -lbz2 -v -static -Wl,-static  --embed-file /usr/local/lib/python3.13/encodings/ --embed-file /usr/local/lib/python3.13/platform.py@/usr/local/lib/python3.13/platform.py -fdeclspec &> emcc.log

# this works, but takes up around 340MB for the wasm output!
# emcc python_arch.c --pre-js ModuleSettings.js -o a.html $(python3-config --includes --embed) -L/home/pradeep/projects/cpython/builddir/emscripten-node-dl $(python3-config --libs --embed) /home/pradeep/projects/cpython/builddir/emscripten-node-dl/Modules/_decimal/libmpdec/libmpdec.a ../cpython/builddir/emscripten-node-dl/Modules/_hacl/libHacl_Hash_SHA2.a ../cpython/builddir/emscripten-node-dl/Modules/expat/libexpat.a /opt/emsdk/upstream/emscripten/cache/sysroot/lib/wasm32-emscripten/libsqlite3-mt.a -lz -lbz2 -v -static -Wl,-static  --embed-file /usr/local/lib/python3.13/encodings/ --embed-file /usr/local/lib/python3.13@/usr/local/lib/python3.13/ -fdeclspec -s INITIAL_MEMORY=328MB &> emcc.log

import sys
import platform
# import niranjan
# print ("python_arch.py!")

print("Is 64 bit: %x" % sys.maxsize, sys.maxsize > 2**32)
print("Platform: %s" % platform.architecture()[0])