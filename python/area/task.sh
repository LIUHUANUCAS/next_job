#!/bin/zsh

set -ex

timeStr=`date  +"%Y-%m-%d_%H:%M:%S_%s"`
echo $timeStr
filename="$timeStr.json"
echo $filename
fname=$1
src=src
riskdir=new_risk
today_filename="$src/$filename"
yestoday_filename=`ls $riskdir/*.txt | grep 'new_risk'|awk '{print substr($1,0,10)}'|sort -r| head -1`
yes_time=` date  -v -1d +"%Y-%m-%d"`
yestoday_filename=`ls $riskdir | grep new_risk | grep $yes_time|head -1`

# url="https://diqu.gezhong.vip/api.php"
# curl $url  > "$today_filename"
python3 get_interface.py "$today_filename"

python3 generate-risk_loc-file.py "$today_filename"
today_time=`date +"%Y-%m-%d"`
today=`ls $riskdir | grep new_risk | grep $today_time|head -1`

fname=`date +"%m%d"`
fname="sql-$fname.sql"
python3 diff.py "$riskdir/$today" "$riskdir/$yestoday_filename" > sql/$fname