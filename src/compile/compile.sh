#!/bin/bash

# This script will compile fastText using Emscripten.

# Navigate out of the fasttext-web directory
cd ../../../

# If the [emsdk] directory does not exist
if [ ! -d "emsdk" ]
then
    # Get the emsdk repo
    git clone https://github.com/emscripten-core/emsdk.git

    # Enter that directory
    cd emsdk

    # Download and install the latest SDK tools
    ./emsdk install latest

    # Make the latest SDK active for the current user. (writes ~/.emscripten file)
    ./emsdk activate latest

# If the [emsdk] directory does exist
else
   # Enter that directory
   cd emsdk

   # Fetch the latest version of the emsdk
   git pull
fi

# Activate PATH and other environment variables in the current terminal
source ./emsdk_env.sh

# Navigate into the correct directory
cd ../fasttext-web/src/

# Compile the C++ 11 files and output the WebAssembly files
emcc args.cc matrix.cc dictionary.cc loss.cc productquantizer.cc densematrix.cc quantmatrix.cc vector.cc model.cc utils.cc meter.cc fasttext.cc main.cc -s EXIT_RUNTIME=1 -s DISABLE_EXCEPTION_CATCHING=0 -std=c++11 -o ../index.html