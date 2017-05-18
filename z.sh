#!/bin/bash

make t

for filename in ./test/*.ss; do
    #echo "Looking at file: " $filename
    ./test/P3.out $filename
done

for filename in ./test/Team*.cpp; do
    echo "-----------------------"
    echo "Running and compiling..: " $filename
    g++ $filename
    ./a.out
done
