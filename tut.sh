#!/bin/sh

dir='./test-ut'

./unspace <${dir}/input.c >${dir}/minified.c || exit 1
diff ${dir}/minified.c ${dir}/reference.c || exit 2

./test-recursive/tiny <${dir}/input.c >${dir}/minified.c || exit 3
diff ${dir}/minified.c ${dir}/reference.c || exit 4
