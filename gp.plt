set datafile separator "\t"
set title "Sorting Algorithms Comparison"
set xlabel "Size of the array"
set ylabel "Time in seconds"

set key left

set xtics 50


set tics font "Helvetica,10"



# plot "matrix.dat" using 2:xtic(1) title 'Tri Selection O(n^2)' with lines, \
#      "matrix.dat" using 3:xtic(1) title 'Tri Fusion O(nlogn)' with lines, \
#      "matrix.dat" using 4:xtic(1) title 'Tri Rapide O(nlogn)' with lines, \
#      "matrix.dat" using 5:xtic(1) title 'Tri Par Dénombrement O(n+k)' with lines, \



plot "matrix.dat" using 2 title 'Tri Selection O(n^2)' with lines, \
     "matrix.dat" using 3 title 'Tri Fusion O(nlogn)' with lines, \
     "matrix.dat" using 4 title 'Tri Rapide O(nlogn)' with lines, \
     "matrix.dat" using 5 title 'Tri Par Denombrement O(n+k)' with lines, \