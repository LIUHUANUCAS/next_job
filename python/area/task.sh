#!/bin/zsh

set -ex

timeStr=`date  +"%Y-%m-%d_%H:%M:%S_%s"`
echo $timeStr
filename="$timeStr.json"
echo $filename
fname=$1
src=src
today_filename="$src/$filename"
yestoday_filename=`ls *.txt | grep 'new_risk'|awk '{print substr($1,0,10)}'|sort -r| head -1`
yes_time=` date  -v -1d +"%Y-%m-%d"`
yestoday_filename=`ls | grep new_risk | grep $yes_time|head -1`

url="https://diqu.gezhong.vip/api.php"
curl $url | jq > "$today_filename"

python3 generate-risk_loc-file.py "$today_filename"
today_time=`date +"%Y-%m-%d"`
today=`ls | grep new_risk | grep $today_time|head -1`

fname=`date +"%m%d"`
fname="sql-$fname.sql"
python3 diff.py "$today" "$yestoday_filename" > sql/$fname