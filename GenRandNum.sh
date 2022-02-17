#!/bin/bash
#This script generates a list of Random Number
#Author: Eduonix
#Date: Oct 2015

# DIFF=$(($2-$1+1))
# RANDOM=$$
# for i in `seq $3`
# do
# 	R=$(($(($RANDOM%$DIFF))+$1))
# 	echo $R
# done

awk -v loop=$2 -v range=$1 'BEGIN{
  srand()
  do {
    numb = 1 + int(rand() * range)
    if (!(numb in prev)) {
       print numb
       prev[numb] = 1
       count++
    }
  } while (count<loop)
}'