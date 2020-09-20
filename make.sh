#!/bin/sh
CFLAGS='-g -O0 -Wall -Wpedantic'
cc $CFLAGS unspace.c -o unspace || exit 1
