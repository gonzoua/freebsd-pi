# $FreeBSD: projects/armv6/tools/regression/usr.bin/printf/regress.sh 222418 2011-05-28 11:37:47Z jilles $

REGRESSION_START($1)

echo '1..11'

REGRESSION_TEST(`b', `printf "abc%b%b" "def\n" "\cghi"')
REGRESSION_TEST(`d', `printf "%d,%5d,%.5d,%0*d,%.*d\n" 123 123 123 5 123 5 123')
REGRESSION_TEST(`f', `printf "%f,%-8.3f,%f,%f\n" +42.25 -42.25 inf nan')
REGRESSION_TEST(`l1', `LC_ALL=en_US.ISO8859-1 printf "%d\n" $(printf \"\\344)')
REGRESSION_TEST(`l2', `LC_ALL=en_US.UTF-8 printf "%d\n" $(printf \"\\303\\244)')
REGRESSION_TEST(`m1', `printf "%c%%%d\0\045\n" abc \"abc')
REGRESSION_TEST(`m2', `printf "abc\n\cdef"')
REGRESSION_TEST(`m3', `printf "%%%s\n" abc def ghi jkl')
REGRESSION_TEST(`m4', `printf "%d,%f,%c,%s\n"')
REGRESSION_TEST(`m5', `printf -- "-d\n"')
REGRESSION_TEST(`s', `printf "%.3s,%-5s\n" abcd abc')

REGRESSION_END()
