#!/bin/sh

echo "model,method,attack,n,k,R,time"

for i in 100 500 1000 5000
do
    echo $i `../fast -h BA_${i}_5.csv -t` | xargs | awk '{print "BA,Fast-R,HDA," $1 "," 5 "," $2 "," $3}'
    echo $i `../fast -h ER_${i}_5.csv -t` | xargs | awk '{print "ER,Fast-R,HDA," $1 "," 5 "," $2 "," $3}'
    echo $i `../fast -h WS_${i}_5.csv -t` | xargs | awk '{print "WS,Fast-R,HDA," $1 "," 5 "," $2 "," $3}'
    echo $i `../fast -h C_${i}.csv -t` | xargs | awk '{print "Completed,Fast-R,HDA," $1 "," $1-1 "," $2 "," $3}'
    echo $i `../fast -h S_${i}.csv -t` | xargs | awk '{print "Star,Fast-R,HDA," $1 "," 1 "," $2 "," $3}'

    echo $i `../fast -r BA_${i}_5.csv -t` | xargs | awk '{print "BA,Fast-R,RA," $1 "," 5 "," $2 "," $3}'
    echo $i `../fast -r ER_${i}_5.csv -t` | xargs | awk '{print "ER,Fast-R,RA," $1 "," 5 "," $2 "," $3}'
    echo $i `../fast -r WS_${i}_5.csv -t` | xargs | awk '{print "WS,Fast-R,RA," $1 "," 5 "," $2 "," $3}'
    echo $i `../fast -r C_${i}.csv -t` | xargs | awk '{print "Completed,Fast-R,RA," $1 "," $1-1 "," $2 "," $3}'
    echo $i `../fast -r S_${i}.csv -t` | xargs | awk '{print "Star,Fast-R,RA," $1 "," 1 "," $2 "," $3}'

    echo $i `../slow -h BA_${i}_5.csv -t` | xargs | awk '{print "BA,SLOW-R,HDA," $1 "," 5 "," $2 "," $3}'
    echo $i `../slow -h ER_${i}_5.csv -t` | xargs | awk '{print "ER,SLOW-R,HDA," $1 "," 5 "," $2 "," $3}'
    echo $i `../slow -h WS_${i}_5.csv -t` | xargs | awk '{print "WS,SLOW-R,HDA," $1 "," 5 "," $2 "," $3}'
    echo $i `../slow -h C_${i}.csv -t` | xargs | awk '{print "Completed,SLOW-R,HDA," $1 "," $1-1 "," $2 "," $3}'
    echo $i `../slow -h S_${i}.csv -t` | xargs | awk '{print "Star,SLOW-R,HDA," $1 "," 1 "," $2 "," $3}'

    echo $i `../slow -r BA_${i}_5.csv -t` | xargs | awk '{print "BA,SLOW-R,RA," $1 "," 5 "," $2 "," $3}'
    echo $i `../slow -r ER_${i}_5.csv -t` | xargs | awk '{print "ER,SLOW-R,RA," $1 "," 5 "," $2 "," $3}'
    echo $i `../slow -r WS_${i}_5.csv -t` | xargs | awk '{print "WS,SLOW-R,RA," $1 "," 5 "," $2 "," $3}'
    echo $i `../slow -r C_${i}.csv -t` | xargs | awk '{print "Completed,SLOW-R,RA," $1 "," $1-1 "," $2 "," $3}'
    echo $i `../slow -r S_${i}.csv -t` | xargs | awk '{print "Star,SLOW-R,RA," $1 "," 1 "," $2 "," $3}'

done
