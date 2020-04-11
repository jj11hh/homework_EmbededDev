#!/usr/bin/env bash

read line #读一行

if [[ $line =~ [a-zA-Z] ]] #含字母
then
    echo "yes"
else
    echo "no"
fi
