Virtual file systems:
  * wasm output works in nodejs but not in browser
    * requires "-lnodefs.js -lnoderawfs.js" flags
  * understand more about using python in embedded systems
    * https://docs.python.org/3/c-api/intro.html#embedding-python
  * figure out what files are being used to instantiate wasm port of python
    * Module.logReadFiles might help here -- https://emscripten.org/docs/api_reference/module.html#Module.logReadFiles
  * investigate virtual file systems
    * IDBFS might help here -- https://emscripten.org/docs/api_reference/Filesystem-API.html#filesystem-api-idbfs
    * maybe site packages location can be customized through https://docs.python.org/3/c-api/init.html#c.Py_SetPythonHome
    * also check https://docs.python.org/3/c-api/init.html#c.Py_SetProgramName
    * https://stackoverflow.com/questions/39539089/what-files-are-required-for-py-initialize-to-run
    * https://docs.python.org/3/c-api/init.html#c.Py_NoSiteFlag
  * try a hand at embedding/preloading files
    * https://emscripten.org/docs/porting/files/packaging_files.html?highlight=embed#packaging-using-emcc
    * https://stackoverflow.com/questions/45535301/can-i-read-files-from-the-disk-by-using-webassembly
    * https://stackoverflow.com/questions/47313403/passing-client-files-to-webassembly-from-the-front-end

Python modules/site packages in wasm:
  * Do we embed all dependencies?
  * What's the correct path?
  * python -m modulefinder python_arch.py &> modules.txt
  * how about bundling entire app into a single file
    * -- https://github.com/Akrog/pinliner ? it seems broken though...
    * pyinstaller also seems broken
  * --embed-file local_file.py@/usr/local/lib/python3.13/local_file.py

Dynamic Linking Wasm:
 * Why does dynamic linking (.so files) fail when program is run in webassembly?
```
dlopen dynamic linking not enabled. File={/home/pradeep/projects/pyqt-test/env/lib/python3.13/site-packages/PyQt5/QtWidgets.abi3.so}, flags={2}Traceback (most recent call last):
  File "hello_qt.py", line 21, in init hello_qt
    sys.path.insert(0,'env/lib/python3.13/site-packages')
ImportError: niranjan dlopen dynamic linking not enabled
``````
 * Checkout -sALLOW_UNIMPLEMENTED_SYSCALLS=0 (https://github.com/emscripten-core/emscripten/issues/15670) https://vscode.dev/github/emscripten-core/emsdk/blob/main/upstream/emscripten/ChangeLog.md#L54

 * Build pyqt5 from source
  * use emsdk?
  * configure with -static 
