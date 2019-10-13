set datafile separator "\t"
set title "Sorting Algorithms Comparison"
set xlabel "Size of the array"
set ylabel "Time in seconds"

set key left

set tics font "Helvetica,10"




plot "matrix.dat" using 2:xtic(1) title 'Tri Selection' with lines, \
     "matrix.dat" using 3:xtic(1) title 'Tri Insertion' with lines, \
     "matrix.dat" using 4:xtic(1) title 'Tri Fusion' with lines, \
     "matrix.dat" using 5:xtic(1) title 'Tri Rapide' with lines, \
     "matrix.dat" using 6:xtic(1) title 'Tri Shell' with lines,
