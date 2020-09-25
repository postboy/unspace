#!/bin/sh

dir='./test-radical'
CFLAGS='-Wall -Wpedantic'

./unspace <${dir}/small.c >${dir}/reference.c || exit 1

cc $CFLAGS ${dir}/small.c -o ${dir}/small || exit 2
${dir}/small <${dir}/small.c >${dir}/tiny.c || exit 3
diff ${dir}/tiny.c ${dir}/reference.c || exit 4

cc $CFLAGS ${dir}/tiny.c -o ${dir}/tiny || exit 5
${dir}/tiny <${dir}/small.c >${dir}/tiny.c || exit 6
diff ${dir}/tiny.c ${dir}/reference.c || exit 7

${dir}/tiny <${dir}/reference.c >${dir}/tiny.c || exit 8
diff ${dir}/tiny.c ${dir}/reference.c || exit 9

stat -c %s ${dir}/reference.c || exit 10
