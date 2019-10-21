# set datafile separator "\t"
set title "Sorting Algorithms Comparison"
set xlabel "Size of the array (x1000)"
set ylabel "Time in seconds"

set key left

# set xtics 0,500


set tics font "Helvetica,10"

# set autoscale x


plot "data.dat" using 2:xtic(100) title 'Tri Selection O(n^2)' with lines lw 3 smooth bezier, \
     "data.dat" using 3:xtic(100) title 'Tri Fusion O(nlogn)' with lines lw 3 smooth bezier, \
     "data.dat" using 4:xtic(100) title 'Tri Rapide O(nlogn)' with lines lw 3 smooth bezier, \
     "data.dat" using 5:xtic(100) title 'Tri Par Dénombrement O(n+k)' with lines lw 3 smooth bezier, \



# plot "matrix.dat" using 2 title 'Tri Selection O(n^2)' with lines, \
#      "matrix.dat" using 3 title 'Tri Fusion O(nlogn)' with lines, \
#      "matrix.dat" using 4 title 'Tri Rapide O(nlogn)' with lines, \
#      "matrix.dat" using 5 title 'Tri Par Denombrement O(n+k)' with lines, \