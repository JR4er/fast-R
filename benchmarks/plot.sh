#!/bin/sh

gnuplot -e 'suffix="HDA"' fix_n.plt
mpost -tex=latex fix_n_HDA.mp
mv ./fix_n_HDA.0 ~/Documents/Fast-HDA/fix_n_HDA.mps

gnuplot -e 'suffix="RA"' fix_n.plt
mpost -tex=latex fix_n_RA.mp
mv ./fix_n_RA.0 ~/Documents/Fast-HDA/fix_n_RA.mps

gnuplot -e 'suffix="HDA"' fix_k.plt
mpost -tex=latex fix_k_HDA.mp
mv ./fix_k_HDA.0 ~/Documents/Fast-HDA/fix_k_HDA.mps

gnuplot -e 'suffix="RA"' fix_k.plt
mpost -tex=latex fix_k_RA.mp
mv ./fix_k_RA.0 ~/Documents/Fast-HDA/fix_k_RA.mps
