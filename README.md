# fastTextWeb

[fastText](https://fasttext.cc) is a library provided by Facebook, Inc. for efficient text classification and representation learning. It's great for creating highly accurate text classification models in a short period of time. However, it can't easily be used to serve predictions on the web - **fastTextWeb** aims to solve this issue. The project was compiled into JavaScript using Emscripten and can be run using Node.

## Installation
```sh
$ https://github.com/karmdesai/fastTextWeb
$ cd fastTextWeb
$ npm install
```

## Usage
fastTextWeb only supports two commands, which helps keep the project files small. I chose to remove all of the other functions because they're not required in order to make predictions. This means that a potential user could train a model using vanilla fastText and then use fastTextWeb to deploy the model and form predictions on the web.

### Predict
Use ```sh predict``` to obtain the **k** most likely labels for a piece of text. The argument ```sh k``` is optional,and equal to ```sh 1``` by default. Remember to substitute ```sh model.bin``` with the relative path to the model and ```sh sample.txt``` with the relative path to piece of text.

```sh
$ node index.js predict /working/model.bin /working/sample.txt k
```