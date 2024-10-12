import subprocess
import time
import psutil
import random
import os

# Constants as per problem constraints
T_MAX = 10**4
N_MAX = 2.1 * 10**6
S_MAX = 10**5
TOTAL_S_MAX = 2 * 10**8

def generate_test_cases():
    t = random.randint(1, T_MAX)
    total_n = 0
    total_s_length = 0
    test_cases = []

    for _ in range(t):
        n = random.randint(1, min(N_MAX - total_n, 10**5))
        total_n += n
        
        # Ensure at least 20 times as many type 1 queries
        type_1_count = max(n - n//21, n - 2)
        other_types_count = n - type_1_count
        
        queries = ([1] * type_1_count) + \
                  ([0] * (other_types_count // 2)) + \
                  ([2] * (other_types_count - other_types_count // 2))
        random.shuffle(queries)

        case = []
        storage = set()
        for query_type in queries:
            remaining_length = min(S_MAX, TOTAL_S_MAX - total_s_length)
            if remaining_length <= 0:
                break
            s_length = random.randint(1, remaining_length)
            s = ''.join(random.choices('abcdefghijklmnopqrstuvwxyz', k=s_length))
            total_s_length += s_length
            case.append((query_type, s))
            if query_type == 0:
                storage.add(s)
            elif query_type == 2:
                storage.discard(s)

        test_cases.append((case, storage))
        
        if total_n >= N_MAX or total_s_length >= TOTAL_S_MAX:
            break

    return t, test_cases

def write_input_file(t, test_cases):
    with open('input.txt', 'w') as f:
        f.write(f"{t}\n")
        for case, _ in test_cases:
            f.write(f"{len(case)}\n")
            for query_type, s in case:
                f.write(f"{query_type} {s}\n")

def run_cpp_program():
    start_time = time.time()
    process = subprocess.Popen(['2024201030_Q1c.out'], shell=True)
    process.wait()
    end_time = time.time()
    return end_time - start_time

def read_output_file():
    with open('output.txt', 'r') as f:
        return f.read().strip().split('\n')

def verify_output(test_cases, output):
    output_index = 0
    all_correct = True
    for i, (case, final_storage) in enumerate(test_cases):
        case_output = output[output_index:output_index+len(case)]
        output_index += len(case)
        is_correct = all(
            (query_type in [0, 2] and ((s in final_storage) == (out == "true"))) or
            (query_type == 1 and out in ["true", "false"])
            for (query_type, s), out in zip(case, case_output)
        )
        all_correct &= is_correct
        print(f"Test case {i+1} correct: {'Yes' if is_correct else 'No'}")
    return all_correct

def measure_memory_usage(pid):
    process = psutil.Process(pid)
    return process.memory_info().rss / (1024 * 1024)  # in MB

# Compile the C++ program
subprocess.run(['g++', '-O2', '-std=c++17', '2024201030_Q1c.cpp', '-o', '2024201030_Q1c.out'], shell=True)

# Generate and run tests
t, test_cases = generate_test_cases()
print(f"Generated {t} test cases")

# Write input to file
write_input_file(t, test_cases)

# Run the C++ program
execution_time = run_cpp_program()

# Measure memory usage
pid = psutil.Process().pid
memory_usage = measure_memory_usage(pid)

# Read and verify output
output = read_output_file()
all_correct = verify_output(test_cases, output)

print(f"\nExecution time: {execution_time:.6f} seconds")
print(f"Memory usage: {memory_usage:.2f} MB")
print(f"All test cases correct: {'Yes' if all_correct else 'No'}")