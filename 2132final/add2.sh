#!/bin/bash

if(( $# != 2 )); then
    echo usage: ./add2.sh num1 num2
    exit
fi

(( sum= $1 +$2 ))
echo the sum of $1 and $2 is $sum
