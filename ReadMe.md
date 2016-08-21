# GumboDOM

[![Build Status](https://travis-ci.org/prometheansacrifice/gumbo-dom.svg?branch=master)](https://travis-ci.org/prometheansacrifice/gumbo-dom)

GumboDOM is dom implementation written in C++ (partial at first) meant to enable dom traversal over web content. GumboDOM is based on Gumbo parser by Google. At the moment, only partial implementation is targeted and is basically porting Mozilla's [JSDOMParser](https://github.com/mozilla/readability/blob/master/JSDOMParser.js)

## Build instructions

### Build

    $ make

### Unit testing

    $ make unittests

## System requirements
- A C++11-standard-compliant compiler
