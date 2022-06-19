#!/bin/bash
if [[ ! -z "$1" ]]; then
	rm -rf ./tests/$1.in
	rm -rf ./outputs/$1.out
fi