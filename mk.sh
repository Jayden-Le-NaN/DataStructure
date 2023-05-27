#!/bin/zsh

if gcc -g *.c ./library/tree/*.c -o test
then
    echo "Created Successfully"
    echo "------------------------------"
    ./test
else
    echo "------------------------------"
    echo "Failed to Create"
fi
