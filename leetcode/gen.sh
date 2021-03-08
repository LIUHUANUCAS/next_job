#!/bin/bash

name=`bash generate_filename.sh "$1"`
echo $name
src="00-tamplete-file.cpp"
cp  "$src" $name
