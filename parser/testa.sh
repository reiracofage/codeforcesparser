#!/bin/bash

make LETRA
if (( $? != 0 )); then
    exit 1
fi
t=0
while [ -e in$t ]; do
    echo "Teste $t..."
    ./LETRA < in$t | diff - out$t -by
    (( t++ ))
done
