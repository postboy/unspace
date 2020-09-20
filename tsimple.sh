#!/bin/sh

dir='./test-simple'
CFLAGS='-Wall -Wpedantic'

./unspace <${dir}/example.c >${dir}/minified.c || exit 1
diff ${dir}/minified.c ${dir}/reference.c || exit 1

./unspace <${dir}/reference.c >${dir}/minified.c || exit 1
diff ${dir}/minified.c ${dir}/reference.c || exit 1

cc $CFLAGS ${dir}/minified.c -o ${dir}/minified || exit 1

${dir}/minified <${dir}/example.c >${dir}/minified.c || exit 1
diff ${dir}/minified.c ${dir}/reference.c || exit 1

${dir}/minified <${dir}/reference.c >${dir}/minified.c || exit 1
diff ${dir}/minified.c ${dir}/reference.c || exit 1
