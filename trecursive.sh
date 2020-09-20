#!/bin/sh

dir='./test-recursive'
CFLAGS='-Wall -Wpedantic'

./unspace <${dir}/small.c >${dir}/reference.c || exit 1

cc $CFLAGS ${dir}/small.c -o ${dir}/small || exit 1
${dir}/small <${dir}/small.c >${dir}/tiny.c || exit 1
diff ${dir}/tiny.c ${dir}/reference.c || exit 1

cc $CFLAGS ${dir}/tiny.c -o ${dir}/tiny || exit 1
${dir}/tiny <${dir}/small.c >${dir}/tiny.c || exit 1
diff ${dir}/tiny.c ${dir}/reference.c || exit 1

${dir}/tiny <${dir}/reference.c >${dir}/tiny.c || exit 1
diff ${dir}/tiny.c ${dir}/reference.c || exit 1

stat -c %s ${dir}/reference.c || exit 1
