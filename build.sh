#!/bin/sh

CC=cc
INCLUDE="-Iinclude"
CFLAGS="-Wall -Wextra -pedantic"
LDFLAGS="-Llib -ldiscord -lcurl -ljson-c"

$CC main.c -o TeatimeBot $INCLUDE $CFLAGS $LDFLAGS

