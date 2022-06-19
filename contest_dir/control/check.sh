#!/bin/bash
PASS=1
if [[ -e "a.out" ]]; then
	for (( i = 1; i <= 1000; i++ )); do
		if [[ -e "./tests/$i.in" ]]; then	
			./a.out < ./tests/$i.in > ./outputs/temp.out
			diff ./outputs/temp.out ./outputs/$i.out > ./outputs/diffres
			if [[ -s ./outputs/diffres ]]; then
				# we found a test we are failing
				printf "FAIL! on test $i check WA dir.\n"
				rm -rf ./WA/*
				cp ./outputs/temp.out ./WA/your\_answer.out
				cp ./outputs/$i.out ./WA/$i.out
				cp ./tests/$i.in ./WA/$i.in
				cp ./outputs/diffres ./WA/diffres.txt
				rm -rf ./outputs/temp.out
				rm -rf ./outputs/diffres
				PASS=0
				break
			else
				rm -rf ./outputs/temp.out
				rm -rf ./outputs/diffres
			fi
		fi
	done
	if [[ PASS -eq 1 ]]; then
		printf "PASS!\n"
	fi
else
	printf "You haven't even compiled the file! Should be named a.out (default).\n"
fi