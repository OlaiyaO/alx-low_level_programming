#!/bin/bash
gcc -c -fPIC $(ls *.c | grep -v 'main.c')
gcc -shared -o liball.so *.o
