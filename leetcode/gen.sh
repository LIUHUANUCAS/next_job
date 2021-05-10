#!/bin/bash

bname=`basename $0`
if [ $# -ne 1 ];then 
    echo "./$bname '1. Two Sum' => 1-Two-Sum.cpp"
    exit 0
fi
getname="filename.sh"
curdir=`dirname $0`
name=`bash $curdir/$getname "$1"`
echo $name
src="$curdir/00-tamplete-file.cpp"
cp  "$src" $name
