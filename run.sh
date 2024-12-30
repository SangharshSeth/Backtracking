#!/usr/bin/env bash

if [ "$#" -ne 1 ]; then
	echo "Usage: $0 <cpp_file>"
	exit 1
fi

cpp_file=$1
output_file="${cpp_file%.cpp}.out"

echo "Compilation Successful."

clang++ -std=c++11 -o "$output_file" "$cpp_file"

if [ $? -eq 0 ]; then
	./"$output_file"
else
	echo "Compilation failed."
fi
