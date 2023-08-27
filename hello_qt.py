### gcc way
# cython --embed hello_qt.py
# gcc hello_qt.c $(python3-config --includes --embed) $(python3-config --ldflags --embed) $(python3-config --libs --embed) $(python3-config --cflags --embed) -rdynamic &> gcc.log

### emcc way
# python -m venv env
# source env/bin/activate
# python -m pip install pyqt6
# python hello_qt.py

# emcc hello_qt.c --pre-js ModuleSettings.js  $(python3-config --includes --embed) -L/home/pradeep/projects/cpython/builddir/emscripten-node-dl $(python3-config --libs --embed) /home/pradeep/projects/cpython/builddir/emscripten-node-dl/Modules/_decimal/libmpdec/libmpdec.a ../cpython/builddir/emscripten-node-dl/Modules/_hacl/libHacl_Hash_SHA2.a ../cpython/builddir/emscripten-node-dl/Modules/expat/libexpat.a /opt/emsdk/upstream/emscripten/cache/sysroot/lib/wasm32-emscripten/libsqlite3-mt.a -lz -lbz2 -v -static -Wl,-static --embed-file env/lib/python3.13/site-packages@/usr/local/lib/python3.13/site-packages -fdeclspec -Wimplicit-function-declaration -s INITIAL_MEMORY=410MB &> emcc.log

# emcc hello_qt.c --pre-js ModuleSettings.js -o a.html $(python3-config --includes --embed) -L/home/pradeep/projects/cpython/builddir/emscripten-node-dl $(python3-config --libs --embed) /home/pradeep/projects/cpython/builddir/emscripten-node-dl/Modules/_decimal/libmpdec/libmpdec.a ../cpython/builddir/emscripten-node-dl/Modules/_hacl/libHacl_Hash_SHA2.a ../cpython/builddir/emscripten-node-dl/Modules/expat/libexpat.a /opt/emsdk/upstream/emscripten/cache/sysroot/lib/wasm32-emscripten/libsqlite3-mt.a -lz -lbz2 -v -static -Wl,-static  --embed-file /usr/local/lib/python3.13/ --embed-file env/lib/python3.13/site-packages@/usr/local/lib/python3.13/site-packages -fdeclspec -s INITIAL_MEMORY=550MB 

print ("hello world from qt!")

import sys
sys.path.insert(0,'env/lib/python3.13/site-packages')
print ("sys.path = %s", sys.path)

from PyQt5 import QtWidgets

print ("qt imported fine!")

app = QtWidgets.QApplication([])
btn = QtWidgets.QPushButton("This is a button")

btn.show()
app.exec()

print ("qt app exited!")
