#!/bin/bash

echo "$1" |sed 's/\.//g'|sed 's/ /-/g'|xargs -n1 -I{} echo {}.cpp
