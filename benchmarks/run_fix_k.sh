#!/bin/sh

echo "model,method,attack,n,k,R,time"

for i in `seq 10000 10000 1000000`
do
    echo $i >&2
    echo BA HDA >&2
    echo $i `../fast -h BA_${i}_100.csv -t` | xargs | awk '{print "BA,Fast-R,HDA," $1 "," 100 "," $2 "," $3}'
    echo ER HDA >&2
    echo $i `../fast -h ER_${i}_100.csv -t` | xargs | awk '{print "ER,Fast-R,HDA," $1 "," 100 "," $2 "," $3}'
    echo WS HDA >&2
    echo $i `../fast -h WS_${i}_100.csv -t` | xargs | awk '{print "WS,Fast-R,HDA," $1 "," 100 "," $2 "," $3}'
    echo BA RA >&2
    echo $i `../fast -r BA_${i}_100.csv -t` | xargs | awk '{print "BA,Fast-R,RA," $1 "," 100 "," $2 "," $3}'
    echo ER RA >&2
    echo $i `../fast -r ER_${i}_100.csv -t` | xargs | awk '{print "ER,Fast-R,RA," $1 "," 100 "," $2 "," $3}'
    echo WS RA >&2
    echo $i `../fast -r WS_${i}_100.csv -t` | xargs | awk '{print "WS,Fast-R,RA," $1 "," 100 "," $2 "," $3}'
done
