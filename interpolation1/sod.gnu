set term postscript eps  enhanced color 
set output 'pic.eps' 

#set key font ", 26"
#set key spacing 4
#set tics font ", 25"
#set xtics 0,0.2,1
#set ylabel 'Density' font ", 33"
#set xlabel 'x' font ", 33"
#set yran[0.1:1.1]
#set key right top

p  'forward' u 1:3 t 'Exact' w lp lw 2,\
   'forward' u 1:2 t 'Forward difference' w lp pt 3  ps 2 lw 1,\
   'backward' u 1:2 t 'Backward difference' w lp pt 4  ps 2 lw 1,\
   'crank-nicolson' u 1:2 t 'Crank-Nicolson'  w lp pt 1 ps 2 lw 1  


