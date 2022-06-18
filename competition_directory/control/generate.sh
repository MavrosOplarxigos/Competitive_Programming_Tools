#!bin/bash
mydir=${PWD##*/}
TESTS=0
if [[ -z "$1" ]]; then
	TESTS=10
else
	TESTS=$1
fi
if [[ -e testgen ]] && [[ -e naive\_$mydir ]]; then
	CURR=1
	while [[ $TESTS -gt 0 ]]; do
		while [[ -e ./tests/$CURR.in ]]; do
			((CURR++))
		done
		touch ./tests/$CURR.in
		touch ./outputs/$CURR.out
		./testgen $CURR > ./tests/$CURR.in
		./naive\_$mydir < ./tests/$CURR.in > ./outputs/$CURR.out
		((TESTS--))
	done
else
	printf "You need to compile both the testgen and naive_$mydir files\n"
fi