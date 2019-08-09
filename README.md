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
Use ```predict``` to obtain the **k** most likely labels for a piece of text. The argument ```k``` is optional,and equal to ```1``` by default. Remember to substitute ```model.bin``` with the relative path to the model and ```sample.txt``` with the relative path to piece of text.

```sh
$ node index.js predict /working/model.bin /working/sample.txt k
```

Alternatively, use ```predict-prob``` to obtain the **k** most likely labels for a piece of text with probabilities. 

```sh
$ node index.js predict-prob /working/model.bin /working/sample.txt k
```

## Documentation
Invoke a command without any arguments in order to list available arguments and their default values.

```sh
$ node index.js predict
usage: fasttext predict[-prob] <model> <test-data> [<k>] [<th>]

  <model>      model filename
  <test-data>  test data filename
  <k>          (optional; 1 by default) predict top k labels
  <th>         (optional; 0.0 by default) probability threshold
```

## Tests
The folder ```tests``` contains several usage examples of ```fastTextWeb```.

### Predict
```sh
$ node index.js predict-prob /working/tests/yelpReviewPolarity/yelpModel.ftz /working/tests/yelpReviewPolarity/sample.txt 2
__label__2 0.72897 __label__1 0.27105
__label__1 0.629605 __label__2 0.370416
__label__1 0.991572 __label__2 0.00844757
```

## What's Next
- [ ] Publish this package to npm registry.
- [ ] Remove more unrequired functions and parts of the source code.
- [ ] Change some of the source code so that the 'index.js' file can be included in a website.