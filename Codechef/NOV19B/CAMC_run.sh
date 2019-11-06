#!/bin/bash

g++ CAMC.cpp -o CAMC.o
g++ CAMC_brute.cpp -o brute.o
g++ CAMC_gen.cpp -o gen.o

for((i = 1; ; i++)); do
    echo $i
    ./gen.o $i > test
    diff -w <(./CAMC.o < test) <(./brute.o < test) || break
done