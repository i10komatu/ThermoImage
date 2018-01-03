set sample 10000

set xlabel "level"
set ylabel

set xrange[0:6]
set yrange[0:256]

f(x) = 255*sin(x*pi/2)
g(x) = 255*cos(x*pi/2)

plot \
x > 4 ? 255 : x > 3 ? f(x-3) : 0 lc rgb "#FF0000" title "R", \
x > 5 ? f(x-5) : x > 4 ? g(x-4) : x > 2 ? 255 : x > 1 ? f(x-1) : 0 lc rgb "#00FF00" title "G",\
x > 5 ? f(x-5) : x > 3 ? 0 : x > 2 ? g(x-2) : x > 1 ? 255 : f(x) lc rgb "#0000FF" title "B"
