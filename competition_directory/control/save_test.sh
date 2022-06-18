#!/bin/bash
CREATED=0
INDEX=1
mydir=${PWD##*/}
# we use numbers of indexes
EMPTY=0
if [[ ! -s input.txt ]]; then
	printf "The input file is empty. Aborting!\n"
	EMPTY=1
fi
while [[ $CREATED -eq 0 ]] && [[ EMPTY -eq 0 ]]; do
	if [[ -e "./tests/$INDEX.in" ]]; then
		((INDEX++))
	else
		CREATED=1
		if [[ -s output.txt ]]; then
			cp input.txt ./tests/$INDEX.in
			cp output.txt ./outputs/$INDEX.out
			rm -rf input.txt
			rm -rf output.txt
			touch input.txt
			touch output.txt
			printf "Saved!\n"
		elif [[ -e naive\_$mydir ]]; then
			./naive\_$mydir < input.txt > output.txt
			cp input.txt ./tests/$INDEX.in
			cp output.txt ./outputs/$INDEX.out
			rm -rf input.txt
			rm -rf output.txt
			touch input.txt
			touch output.txt
			printf "Saved and used naive version to create output!\n"
		else
			printf "The output file is empty and naive version doesn't exist. No tests to save here!\n"
		fi
	fi
done
