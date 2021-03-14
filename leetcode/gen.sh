#!/bin/bash
curdir=`dirname $0`
name=`bash $curdir/generate_filename.sh "$1"`
echo $name
src="$curdir/00-tamplete-file.cpp"
cp  "$src" $name
