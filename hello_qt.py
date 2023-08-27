# python -m venv env
# source env/bin/activate
# python -m pip install pyqt6
# python hello_qt.py

# emcc hello_qt.c --pre-js ModuleSettings.js -o a.html $(python3-config --includes --embed) -L/home/pradeep/projects/cpython/builddir/emscripten-node-dl $(python3-config --libs --embed) /home/pradeep/projects/cpython/builddir/emscripten-node-dl/Modules/_decimal/libmpdec/libmpdec.a ../cpython/builddir/emscripten-node-dl/Modules/_hacl/libHacl_Hash_SHA2.a ../cpython/builddir/emscripten-node-dl/Modules/expat/libexpat.a /opt/emsdk/upstream/emscripten/cache/sysroot/lib/wasm32-emscripten/libsqlite3-mt.a -lz -lbz2 -v -static -Wl,-static  --embed-file /usr/local/lib/python3.13/encodings/ --embed-file /home/pradeep/.local/lib/python3.13/site-packages/PyQt6/__init__.py@/usr/local/lib/python3.13/site-packages/PyQt6/__init__.py -fdeclspec -Wimplicit-function-declaration &> emcc.log

# emcc hello_qt.c --pre-js ModuleSettings.js  $(python3-config --includes --embed) -L/home/pradeep/projects/cpython/builddir/emscripten-node-dl $(python3-config --libs --embed) /home/pradeep/projects/cpython/builddir/emscripten-node-dl/Modules/_decimal/libmpdec/libmpdec.a ../cpython/builddir/emscripten-node-dl/Modules/_hacl/libHacl_Hash_SHA2.a ../cpython/builddir/emscripten-node-dl/Modules/expat/libexpat.a /opt/emsdk/upstream/emscripten/cache/sysroot/lib/wasm32-emscripten/libsqlite3-mt.a -lz -lbz2 -v -static -Wl,-static --embed-file env/lib/python3.13/site-packages@/usr/local/lib/python3.13/site-packages -fdeclspec -Wimplicit-function-declaration -s INITIAL_MEMORY=410MB &> emcc.log

# emcc hello_qt.c --pre-js ModuleSettings.js -o a.html $(python3-config --includes --embed) -L/home/pradeep/projects/cpython/builddir/emscripten-node-dl $(python3-config --libs --embed) /home/pradeep/projects/cpython/builddir/emscripten-node-dl/Modules/_decimal/libmpdec/libmpdec.a ../cpython/builddir/emscripten-node-dl/Modules/_hacl/libHacl_Hash_SHA2.a ../cpython/builddir/emscripten-node-dl/Modules/expat/libexpat.a /opt/emsdk/upstream/emscripten/cache/sysroot/lib/wasm32-emscripten/libsqlite3-mt.a -lz -lbz2 -v -static -Wl,-static  --embed-file /usr/local/lib/python3.13/ --embed-file env/lib/python3.13/site-packages@/usr/local/lib/python3.13/site-packages -fdeclspec -s INITIAL_MEMORY=550MB 

print ("hello world from qt!")

from PyQt5 import QtWidgets

print ("qt imported fine!")

app = QtWidgets.QApplication([])
btn = QtWidgets.QPushButton("This is a button")

btn.show()
app.exec()

print ("qt app exited!")
