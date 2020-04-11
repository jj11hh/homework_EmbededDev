#!/usr/bin/env bash

a_global_var="hello"

echo $a_global_var

function func {
# Try to change it in a function
    a_global_var="a fake global var"
    echo $a_global_var
}

# But I'm still here

echo $a_global_var

# Let's see how many variables I received

echo "Got $# variables"
echo "They are $*"
echo "the first is $1"
echo "the second is $2"
echo "the third is $3"
echo "And, if it's exist, the fourth one is $4"

ls

echo $?

a_command_that_not_exist

echo $?

touch apple # there is a apple here

if [ -f apple ] 
then
    echo "There's a apple!"
fi

rm apple

if [ -f apple ]
then
    echo "The apple still here!"
else
    echo "It's gone!"
fi

# let's try to calculate GCD with Euclid algorithm

if [ $# -lt 2 ]
then
    filename=$(basename $0)
    echo "usage: ${filename} num1 num2" 1>&2
    exit 255
fi

function gcd() {
    local dividend=$1
    local divisor=$2
    local remainder=1

    until [ $remainder -eq 0 ]
    do
        let "remainder = dividend % divisor"
        dividend=$divisor
        divisor=$remainder
    done

    return $dividend
}

gcd $1 $2

echo "GCD of $1 and $2 is $?"

for planet in "Mercury 36" "Venus 67" "Earth 93" "Mars 142" "Jupiter 483"
do
    set -- $planet

    echo -e "${1}\t${2},000,000 miles from the sun."
done

echo "Let's print 0 - 9"

iterator=0

while [ $iterator -lt 10 ]
do
    echo -n "$iterator "
    let "iterator++"
done

case $(arch) in
    i386) echo "80386-based machine";;
    i486) echo "80486-based machine";;
    i586) echo "80586-based machine";;
    i686) echo "80686-based machine";;
    x86_64) echo "amd64-based machine";;
    aarch64) echo "armv8-based machine";;
    armv7h) echo "armv7-based machine";;
esac

PS3="Choose a name for your newborn son:>"

select name in "Xukun" "Weiming" "Qicheng" "Wangpeng"
do
    echo "Yes, your son will be named as $name"
    break
done

count=0

for file in *
do
    if [ -f $file ]
    then
        let "count++"
    fi
done

echo "So there are $count files"

exit 0
