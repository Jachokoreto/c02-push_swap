#!/bin/bash
#This script generates a list of Random Number
#Author: Eduonix
#Date: Oct 2015

DIFF=$(($2-$1+1))
RANDOM=$$
for i in `seq $3`
do
	R=$(($(($RANDOM%$DIFF))+$1))
	echo $R
done