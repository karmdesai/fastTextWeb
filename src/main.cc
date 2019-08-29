/**
 * Copyright (c) 2016-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <sstream>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stdexcept>
#include "args.h"
#include "fasttext.h"

// emscripten
#include <emscripten/bind.h>
#include <emscripten/emscripten.h>

// nodeFS
#ifdef NODERAWFS
#define CWD ""
#else
#define CWD "/working"
#endif
// end nodeFS

using namespace fasttext;

// our instance of fastText
static FastText fastTextInstance;

void testFunction () {
  std::cout << "The test function worked.";
  std::cout << "\n";
}

void printPredictions(
    const std::vector<std::pair<real, std::string>>& predictions,
    bool printProb,
    bool multiline) {
  bool first = true;
  for (const auto& prediction : predictions) {
    if (!first && !multiline) {
      std::cout << " ";
    }
    first = false;
    std::cout << prediction.second;
    if (printProb) {
      std::cout << " " << prediction.first;
    }
    if (multiline) {
      std::cout << std::endl;
    }
  }
  if (!multiline) {
    std::cout << std::endl;
  }
  std::cout << "\n";
}

// this function loads the model
void loadModel(std::string filePath) {
  // the file path will be the 3rd argument
  fastTextInstance.loadModel(filePath);
  std::cout << "The model has successfully been loaded!\n";
  std::cout << "\n";
}

// this function will actually make a prediction
void makePrediction(std::string predictionType, std::string textToClassify, std::string numPredictions, std::string thresholdValue) {
  int32_t k = std::stoi(numPredictions);
  real threshold = std::stof(thresholdValue);
  std::istringstream is(textToClassify);

  bool printProb = predictionType == "predict-prob";

  std::istream& in = is;
  std::vector<std::pair<real, std::string>> predictions;
  while (fastTextInstance.predictLine(in, predictions, k, threshold)) {
    printPredictions(predictions, printProb, false);
  }
  std::cout << "\n";
}

int main(int argc, char** argv) {
  // nodeFS
  #ifndef NODERAWFS
    // mount the current folder as a nodeFS instance
    EM_ASM(
      FS.mkdir('/working');
      FS.mount(NODEFS, { root: '.' }, '/working');
    );
  #endif
  // end nodeFS

  std::cout << "\n";
  return 0;
}

// emscripten bindings
EMSCRIPTEN_BINDINGS(myModule) {
  emscripten::function("testFunction", &testFunction);
  emscripten::function("loadModel", &loadModel);
  emscripten::function("makePrediction", &makePrediction);
}