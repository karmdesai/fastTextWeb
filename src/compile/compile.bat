@ECHO OFF
REM This script will compile fastTextWeb using Emscripten.
REM This will not download & install Emscripten, but it must be activated.
REM In order to download & install Emscripten, visit: https://emscripten.org/docs/getting_started/Tutorial.html

REM Navigate into the 'src' directory
cd ../

REM Compile the C++ 11 files and output the WebAssembly files 
REM Optimization level 2 is being used, which hides some debugging/assertion information
emcc --bind -o ../index.js args.cc matrix.cc dictionary.cc loss.cc productquantizer.cc densematrix.cc quantmatrix.cc vector.cc model.cc utils.cc meter.cc fasttext.cc main.cc -s NO_EXIT_RUNTIME -s WASM=0 -std=c++11 -O2