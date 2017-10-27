#!/bin/sh

#echo "model,method,attack,n,k,R,time"

for i in `seq 100`
do
    #echo $i `../fast -h BA_10000_${i}.csv -t` | xargs | awk '{print "BA,Fast-R,HDA," 10000 "," $1 "," $2 "," $3}'
    #echo $i `../fast -h ER_10000_${i}.csv -t` | xargs | awk '{print "ER,Fast-R,HDA," 10000 "," $1 "," $2 "," $3}'
    #echo $i `../fast -h WS_10000_${i}.csv -t` | xargs | awk '{print "WS,Fast-R,HDA," 10000 "," $1 "," $2 "," $3}'

    echo $i `../fast -r BA_10000_${i}.csv -t` | xargs | awk '{print "BA,Fast-R,RA," 10000 "," $1 "," $2 "," $3}'
    echo $i `../fast -r ER_10000_${i}.csv -t` | xargs | awk '{print "ER,Fast-R,RA," 10000 "," $1 "," $2 "," $3}'
    echo $i `../fast -r WS_10000_${i}.csv -t` | xargs | awk '{print "WS,Fast-R,RA," 10000 "," $1 "," $2 "," $3}'
done
