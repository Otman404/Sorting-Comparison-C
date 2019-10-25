# set datafile separator "\t"
set title "Comparaison des algorithmes de tri"
set xlabel "Taille du tableau (x1000)"
set ylabel "Temps en secondes"

set key left



set tics font "Helvetica,10"



plot "matrix.dat" using 2:xtic(100) title 'Tri par Selection O(n^2)' with lines lw 3 smooth bezier, \
     "matrix.dat" using 3:xtic(100) title 'Tri Fusion O(nlogn)' with lines lw 3 smooth bezier, \
     "matrix.dat" using 4:xtic(100) title 'Tri Rapide O(nlogn)' with lines lw 3 smooth bezier, \
     "matrix.dat" using 5:xtic(100) title 'Tri par Denombrement O(n+k)' with lines lw 3 smooth bezier, \
