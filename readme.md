
## Compilation

### Compile cpython

Clone emsdk and cpython. I put emsdk to `/opt` and cpython into `~/projects`.
cypthon version used `52e0797f8e1c631eecf24cb3f997ace336f52271`.
emsdk version used `350c19a36c3356b3202c108a68a20cd102bdc06b`.

```bash
git clone https://github.com/python/cpython.git ~/projects/cpython
git clone https://github.com/emscripten-core/emsdk.git /opt/emsdk
```

Follow the [wasm build instructions](https://github.com/python/cpython/blob/main/Tools/wasm/README.md#python-webassembly-wasm-build) in cpython.
Make sure that you:
* Build the python interpreter for wasm
* Cross-compile to wasm32-emscripten for browser
* Cross compile to wasm32-emscripten for node

Once these are done, cd into the build output directory for cpython targeting node, and install python to the local system:
```bash
cd ~/projects/cpython/builddir/emscripten-node-dl
sudo make install
```

Once this is done, we can move over to compiling programs in this repo.

### Compile programs
C programs in this repo can be compiled to wasm using emcc.
Each file has a comment block at the top showcasing the full command that can just be copy pasted and run.

Example: `hell_sdl.c` can be compiled using
```bash
emcc hello_sdl.c -o hello_sdl.html
```
which'll output hello_sdl.html.
Please use a local webserver to serve this file [^1]

### FAQ
[^1]:
Due to security concerns, trying to open hello_sdl.html via the `file://` protocol won't work in most browsers.
You can use python's builtin feature to host a server locally via
```bash
python3 http_server.py
```
