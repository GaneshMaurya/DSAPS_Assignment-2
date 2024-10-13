import random

def generate_test_case(max_key_value, remaining_n, remaining_q):
    # Generate random values for `n` and `q` while ensuring the sum does not exceed allowed limits.
    n = random.randint(1, min(remaining_n, 10**5))  # Limit n to a reasonable number per test case.
    q = random.randint(1, min(remaining_q, 10**4))  # Limit q similarly.
    
    # Generate random key-value pairs
    kv_pairs = [(random.randint(1, max_key_value), random.randint(1, max_key_value)) for _ in range(n)]
    key_value_map = {k: v for k, v in kv_pairs}  # Create the key-value map

    # Convert keys to a list for efficient access during query generation
    keys_list = list(key_value_map.keys())

    # Generate queries for random keys (some may not be in kv_pairs)
    queries = [random.choice([random.choice(keys_list), random.randint(1, max_key_value)]) for _ in range(q)]

    return (kv_pairs, queries, n, q)

def execute_test_case(kv_pairs, queries):
    # Initialize a dictionary to store key-value pairs
    store = {}
    
    # Insert key-value pairs into the dictionary (overwriting if key already exists)
    for k, v in kv_pairs:
        store[k] = v
    
    # Generate responses for the queries
    responses = [store.get(q_key, 0) for q_key in queries]
    return responses

def write_test_cases_and_output_to_file(input_file, output_file, max_key_value=10**18, max_total_nq=2 * 10**5):
    test_cases = []
    total_n = 0
    total_q = 0
    
    # Keep generating test cases until the combined n and q stay within the limit
    while total_n + total_q < max_total_nq:
        remaining_n = max_total_nq - total_n
        remaining_q = max_total_nq - total_q
        
        # Generate a test case
        kv_pairs, queries, n, q = generate_test_case(max_key_value, remaining_n, remaining_q)
        
        # Update totals
        total_n += n
        total_q += q
        
        # Add to test cases list
        test_cases.append((kv_pairs, queries))
    
    # Write test cases to input and output files
    with open(input_file, 'w') as infile, open(output_file, 'w') as outfile:
        # Write the number of test cases
        t = len(test_cases)
        infile.write(f"{t}\n")
        
        for kv_pairs, queries in test_cases:
            # Write the number of key-value pairs
            infile.write(f"{len(kv_pairs)}\n")
            
            # Write each key-value pair
            for k, v in kv_pairs:
                infile.write(f"{k} {v}\n")
            
            # Write the number of queries
            infile.write(f"{len(queries)}\n")
            
            # Write each query
            for q_key in queries:
                infile.write(f"{q_key}\n")
            
            # Generate the output for the test case and write it to the output file
            output = execute_test_case(kv_pairs, queries)
            for result in output:
                outfile.write(f"{result}\n")

# Specify the file names
input_file = 'input11.txt'
output_file = 'output11.txt'

# Generate test cases and write to files
write_test_cases_and_output_to_file(input_file, output_file)

print(f"Test cases have been written to {input_file} and corresponding outputs to {output_file}.")
