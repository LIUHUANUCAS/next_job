#!/bin/bash

rm -f test && g++ $1 -std=c++11 -o test -g && ./test
