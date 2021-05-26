#!/bin/bash

if [ $# -ne 2 ]; then
    echo "[usage]:bash $0 source_dir dest_dir"
    exit -1
fi
set -e

src=$1
dest=$2
mkdir -p $dest
for file in $(
    find $src | grep parquet$ | grep -v $dest
); do
    filesize=$(du -sh $file | awk '{print $1}')
    echo "cp $file to $dest, size:$filesize"
    cp $file $dest
done

# find $src | grep parquet$ | grep -v $dest | xargs -n1 -I{} cp {} $dest
