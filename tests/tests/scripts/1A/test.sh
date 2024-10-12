#!/bin/bash

# rm -r tests
mkdir tests
g++ -O3 sol.cc -o sol

TEST_FILES=5
T_MAX=1
N_MAX=5
Q_MAX=5
KV_MAX=5
for ((i=0; i<$TEST_FILES; i++)); do
    python gen.py $T_MAX $N_MAX $Q_MAX $KV_MAX > tests/test_${i}.in
    ./sol < tests/test_${i}.in > tests/test_${i}.out
done

# rm sol

# Here, the actual output of test_0 is corrupted to show failure
# echo "CORRUPTION" >> tests/test_0.out

# replace with your program
g++ brute.cc -o brute

for input_file in tests/test_*.in; do
    output_file="${input_file%.in}.out"

    ./brute < "$input_file" > temp_output.txt

    if diff -q temp_output.txt "$output_file" > /dev/null; then
        echo -e "\e[32mSuccess: $input_file\e[0m"
    else
        echo -e "\e[31mFailure: $input_file\e[0m"
    fi
done

# rm temp_output.txt
