#!/bin/bash

id=$1

dir=$(dirname $0)
dir=$(realpath $dir)

wget http://www.codeforces.com/contest/$id -O main.html
n=$(grep 'title="Submit"' main.html | wc -l)
rm -f main.html

L="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
((n--))
last=${L:$n:1}
list=$(echo "echo {A..${last}}" | bash)

for l in $list; do
    mkdir $l
    cd $l
    wget http://www.codeforces.com/contest/${id}/problem/$l -O problem${l}.html
    ${dir}/gerainout < problem${l}.html
    cp ${dir}/modelo.cpp ${l}.cpp
    cp ${dir}/Makefile .
    cp ${dir}/testa.sh .
    sed -i "s/LETRA/${l}/g" testa.sh
    cd ..
done
