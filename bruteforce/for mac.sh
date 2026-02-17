#!/bin/bash

while true
do
    ./gen > in
    ./sol < in > out
    ./brute < in > ok

    diff out ok > /dev/null
    if [ $? -ne 0 ]; then
        echo "Mismatch found!"
        break
    fi

    echo "Test passed"
done
