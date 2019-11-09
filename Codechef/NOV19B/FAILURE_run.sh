#!/bin/bash

g++ FAILURE.cpp -o FAILURE.o
g++ FAILURE_brute.cpp -o brute.o
g++ FAILURE_gen.cpp -o gen.o

for((i = 1; ; i++)); do
    echo $i
    ./gen.o $i > test
    diff -w <(./FAILURE.o < test) <(./brute.o < test) || break
done