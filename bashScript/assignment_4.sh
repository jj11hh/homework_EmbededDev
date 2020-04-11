#/usr/bin/env bash

string_to_search=$1
dir_for_search=$2

if [ $# -ne 2 ]
then
    echo "usage: $0 STRING DIRECTORY"
    exit 1
fi

find $dir_for_search -xtype f -exec grep $string_to_search {} \;

