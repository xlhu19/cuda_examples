#!/bin/bash
 
date1="2017-4-23 12:00:00"
date2="2017-4-24 15:00:00"
 
t1=`date -d "$date1" +%s`
t2=`date -d "$date2" +%s`
 
if [ $t1 -gt $t2 ]; then
    echo "$date1 > $date2"
elif [ $t1 -eq $t2 ]; then
    echo "$date1 == $date2"
else
    echo "$date1 < $date2"
fi
