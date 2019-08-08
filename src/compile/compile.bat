@ECHO OFF
REM This script will compile fastTextWeb using Emscripten.
REM This will not download & install Emscripten since Windows doesn't have Git built in.
REM In order to download & install Emscripten, visit: https://emscripten.org/docs/getting_started/Tutorial.html

REM Navigate into the 'src' directory
cd ../

REM Compile the C++ 11 files and output the WebAssembly files 
emcc args.cc matrix.cc dictionary.cc loss.cc productquantizer.cc densematrix.cc quantmatrix.cc vector.cc model.cc utils.cc meter.cc fasttext.cc main.cc -s EXIT_RUNTIME=1 -s DISABLE_EXCEPTION_CATCHING=0 -std=c++11 -o ../index.js