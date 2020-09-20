#!/bin/sh

dir='./test-simple'
CFLAGS='-Wall -Wpedantic'

./unspace <${dir}/example.c >${dir}/minified.c || exit 1
diff ${dir}/minified.c ${dir}/reference.c || exit 2

./unspace <${dir}/reference.c >${dir}/minified.c || exit 3
diff ${dir}/minified.c ${dir}/reference.c || exit 4

cc $CFLAGS ${dir}/minified.c -o ${dir}/minified || exit 5

${dir}/minified <${dir}/example.c >${dir}/minified.c || exit 6
diff ${dir}/minified.c ${dir}/reference.c || exit 7

${dir}/minified <${dir}/reference.c >${dir}/minified.c || exit 8
diff ${dir}/minified.c ${dir}/reference.c || exit 9
