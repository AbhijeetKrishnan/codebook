#!/bin/bash

g++ $PWD/$1.cpp -o $PWD/$1.o
g++ $PWD/$1_brute.cpp -o $PWD/brute.o
g++ $PWD/$1_gen.cpp -o $PWD/gen.o

for((i = 1; ; i++)); do
    echo $i
    ./gen.o $i > test
    diff -w <(./$1.o < test) <(./brute.o < test) || break
done