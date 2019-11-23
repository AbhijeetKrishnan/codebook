#!/bin/bash

g++ $1.cpp -o $1.o
g++ $1_brute.cpp -o brute.o
g++ $1_gen.cpp -o gen.o

for((i = 1; ; i++)); do
    echo $i
    ./gen.o $i > test
    diff -w <(./$1.o < test) <(./brute.o < test) || break
done