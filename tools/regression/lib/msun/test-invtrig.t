#!/bin/sh
# $FreeBSD: projects/armv6/tools/regression/lib/msun/test-invtrig.t 181076 2008-07-31 22:43:38Z das $

cd `dirname $0`

executable=`basename $0 .t`

make $executable 2>&1 > /dev/null

exec ./$executable
