/*
 * Copyright 2011 The Emscripten Authors.  All rights reserved.
 * Emscripten is available under two separate licenses, the MIT license and the
 * University of Illinois/NCSA Open Source License.  Both these licenses can be
 * found in the LICENSE file.
 */

// Build instructions:
// /opt/emsdk/emsdk activate latest
// source "/opt/emsdk/emsdk_env.sh"
// emcc hello_world.c -o hello_world.html

#include <stdio.h>

int main() {
  printf("hello, world!\n");
  return 0;
}
