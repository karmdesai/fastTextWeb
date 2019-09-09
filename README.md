# fastTextWeb

[fastText](https://fasttext.cc) is a library provided by Facebook, Inc. for efficient text classification and representation learning. It's great for creating highly accurate text classification models in a short period. However, it can't easily be used to serve predictions on the web - **fastTextWeb** aims to solve this issue. The project was compiled into JavaScript using Emscripten and can be used in a browser or run using Node.

## Installation
```sh
$ npm install fasttextweb
```

## Usage
fastTextWeb only supports two commands, which helps keep the project files small. I chose to remove all of the other functions because they're not required in order to make predictions. This means that a potential user could train a model using vanilla fastText and then use fastTextWeb to deploy the model and form predictions on the web.

**All arguments are expected to be strings, so ensure you use quotation marks when you input arguments.**

### loadModel
Use ```loadModel``` to load a fastText model. The command takes in one argument, ```model```.

```sh
$ node
> const fastText = require('fasttextweb');
> fastText.loadModel(<model>);
```

This function only takes in one argument, ```model```, which is the relative file path of the model you want to load.

### makePrediction
Use ```makePrediction``` to obtain the most likely labels for a piece of text. The command takes in four arguments, ```predictionType```, ```textToClassify```, ```k```, and ```th```.

```sh
$ node
> const fastText = require('fasttextweb');
> fastText.loadModel(<model>);
> fastText.makePrediction(<predictionType>, <textToClassify>, <k>, <th>);
```

This function takes in multiple arguments, which are all required.

<```predictionType```>: You can use either "predict" or "predict-prob". Use "predict" to obtain the **k** most likely labels for a piece of text. Alternatively, use "predict-prob" to obtain the **k** most likely labels for a piece of text with probabilities.

<```textToClassify```>: Simply enter the piece of text you want to classify, as a string.

<```k```>: The top **k** labels you want to return through the prediction.

<```th```>: The probability threshold ("0.0" was the default used during production).

## Tests
The folder ```tests``` contains several usage examples of ```fastTextWeb```. Below is an example use case of fastTextWeb with the **balesModel** dataset.

```sh
$ node
> const fastText = require('fasttextweb');
> fastText.loadModel("working/tests/balesModel/compressedModel.ftz");
The model has successfully been loaded!

> fastText.makePrediction("predict", "today was a really amazing day!", "1", "0.0");
__label__B

> fastText.makePrediction("predict-prob", "how about we put the spoons in the dishwasher?", "2", "0.0");
__label__C 0.959634 __label__B 0.0348174
```

## What's Next
- [x] Publish this package to the npm registry.
- [x] Remove more unrequired functions and parts of the source code.
- [x] Change some of the source code so that the 'index.js' file can be included in a website.

## Acknowledgements
1. [Stuart Watt](https://github.com/morungos) (Chief Technology Officer of [Turalt](https://github.com/turalt)) - I really appreciate the resources, help, and support that Stuart has provided. This project really wouldn't have been possible without him!
2. [fastText](https://fasttext.cc) - A library provided by Facebook, Inc. for efficient text classification and representation learning.
3. [Emscripten](https://emscripten.org) - A toolchain for compiling to WebAssembly, built using LLVM, that lets you run C and C++ on the web at near-native speed without plugins.