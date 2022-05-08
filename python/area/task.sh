#!/bin/zsh

set -ex

timeStr=`date  +"%Y-%m-%d_%H:%M:%S_%s"`
echo $timeStr
filename="$timeStr.txt"
echo $filename
fname=$1
src=src
today_filename="$src/$filename"
yestoday_filename="$fname"

url="https://diqu.gezhong.vip/api.php"
curl $url | jq > "$today_filename"

python generate-risk_loc-file.py "$today_filename"

# python diff.py "$today_filename" "$yestoday_filename"