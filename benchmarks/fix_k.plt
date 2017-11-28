#!/usr/local/bin/gnuplot
prefix="fix_k"
#suffix="HDA"

ba_file = prefix."_BA_".suffix.".dat"
ws_file = prefix."_WS_".suffix.".dat"
er_file = prefix."_ER_".suffix.".dat"


set term mp latex
set output prefix.'_'.suffix.".mp"

set yrange [0:3000]
set xrange [0:750000]

set xlabel "Number of nodes $N$"
#set xlabel "Average degree $k$"
set ylabel "Elapsed time (ms)"
set size 1, 0.8
set key top left

BA(x)=a1*x+b1
WS(x)=a2*x+b2
ER(x)=a3*x+b3

fit BA(x) ba_file via a1,b1
fit WS(x) ws_file via a2,b2
fit ER(x) er_file via a3,b3

set multiplot
plot ba_file title 'BA', ws_file title 'WS', er_file title 'ER', BA(x) dt 1 notitle, WS(x) dt 2 notitle, ER(x) dt 3 notitle
plot ba_file notitle, ws_file notitle, er_file notitle, BA(x) dt 1 title 'BA', WS(x) dt 2 title 'WS', ER(x) dt 3 title 'ER'
unset multiplot

unset output
