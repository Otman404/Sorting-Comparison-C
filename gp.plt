#!/usr/bin/gnuplot -persist

set title "Algorithms de Tri"
set xlabel "Temps"
set ylabel "Nombre d'elements"
set grid
plot "matrix22.dat" u (column(0)):2:xtic(1) w l title "","matrix22.dat" u (column(0)):3:xtic(1) w l title ""

plot "matrix22.dat"
