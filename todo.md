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
