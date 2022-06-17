#!/bin/bash
PROGRAM="$1"
VERDICT="ALL TESTS PASSED!"
TESTS=20
LENGTH=1000
LOWEST=0
HIGHEST=1000000000000000000
for test in $(seq 1 $TESTS)
do

	echo 'test#'$test': '

	touch input.in
	touch output.out
	./../testgen/random\_integer\_array $LENGTH $LOWEST $HIGHEST $test > ./input.in
	wait
	sleep 1
	# echo 'input generated.'

	./$PROGRAM < input.in > output.out
	wait
	sleep 1
	# echo 'sorting done.'

	CHECKER=$(./checker < output.out)
	wait
	sleep 1
	if [ $CHECKER -gt 0 ]
	then
		echo 'We have a wrong sorting! Check input.in and output.out'
		VERDICT="FAILED."
		break
	else
		echo 'CORRECT!'
		rm -rf input.in
		rm -rf output.out
	fi
done
echo $VERDICT