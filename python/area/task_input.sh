#!/bin/zsh

set -ex
today_filename=$1



yes_time=` date  -v -1d +"%Y-%m-%d"`
yestoday_filename=`ls | grep new_risk | grep $yes_time|head -1`


python3 generate-risk_loc-file.py "$today_filename"
today_time=`date +"%Y-%m-%d"`
today=`ls | grep new_risk | grep $today_time|head -1`

fname=`date +"%m%d"`
fname="sql-$fname.sql"
python3 diff.py "$today" "$yestoday_filename" > sql/$fname