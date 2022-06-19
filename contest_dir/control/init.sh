#!/bin/bash
# case where we give no arguments
if [ -z "$1" ]
then
	# we just generate directories from problems
	for prob in {A..F}; do
		if [ ! -d "../$prob" ]
		then
			mkdir ../$prob/
			mkdir ../$prob/tests
			mkdir ../$prob/outputs
			mkdir ../$prob/WA
			touch ../$prob/input.txt
			touch ../$prob/output.txt
			cp template.cpp ../$prob/$prob.cpp
			cp template.cpp ../$prob/naive\_$prob.cpp
			cp template_testgen.cpp ../$prob/testgen.cpp
			cp save_test.sh ../$prob/save_test.sh
			cp del_test.sh ../$prob/del_test.sh
			cp check.sh ../$prob/check.sh
			cp generate.sh ../$prob/generate.sh
		fi
	done
else
	# we create a directory specifically for the name given as argument
	prob=$1
	mkdir ../$prob/
	mkdir ../$prob/tests
	mkdir ../$prob/outputs
	mkdir ../$prob/WA
	touch ../$prob/input.txt
	touch ../$prob/output.txt
	cp template.cpp ../$prob/$prob.cpp
	cp template.cpp ../$prob/naive\_$prob.cpp
	cp template_testgen.cpp ../$prob/testgen.cpp
	cp save_test.sh ../$prob/save_test.sh
	cp del_test.sh ../$prob/del_test.sh
	cp check.sh ../$prob/check.sh
	cp generate.sh ../$prob/generate.sh
fi
