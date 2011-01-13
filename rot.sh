#!/bin/bash

ord () {
    printf '%d\n' "'$1"
}

chr() {
    printf \\$(printf '%03o' $1)
}


x=`ord $1`
y=`chr $x`
echo $y = $x
