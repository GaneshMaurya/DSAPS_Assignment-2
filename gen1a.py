import random

def generate_test_case():
    # Define constraints
    max_key_value = 10**18
    n = 10**5  # Fixed number of key-value pairs
    q = 10**4  # Fixed number of queries

    test_cases = []
    
    # Generate random key-value pairs
    kv_pairs = [(random.randint(1, max_key_value), random.randint(1, max_key_value)) for _ in range(n)]
    key_value_map = {k: v for k, v in kv_pairs}  # Create the key-value map in one go

    # Convert keys to a list for efficient access during query generation
    keys_list = list(key_value_map.keys())

    # Generate queries for random keys (some may not be in kv_pairs)
    queries = [random.choice([random.choice(keys_list), random.randint(1, max_key_value)]) for _ in range(q)]

    test_cases.append((kv_pairs, queries))
    
    return test_cases


def execute_test_case(test_case):
    kv_pairs, queries = test_case
    
    # Initialize a dictionary to store key-value pairs
    store = {}
    
    # Insert key-value pairs into the dictionary (overwriting if key already exists)
    for k, v in kv_pairs:
        store[k] = v
    
    # Generate responses for the queries
    responses = [store.get(q_key, 0) for q_key in queries]  # Using dict.get() for cleaner code
    return responses


def write_test_cases_and_output_to_file(input_file, output_file):
    test_cases = generate_test_case()

    with open(input_file, 'w') as infile, open(output_file, 'w') as outfile:
        t = len(test_cases)
        
        # Write number of test cases
        infile.write(f"{t}\n")
        
        # Write generated test cases and corresponding output
        for kv_pairs, queries in test_cases:
            # Write the number of key-value pairs
            infile.write(f"{len(kv_pairs)}\n")
            
            # Write each key-value pair
            infile.writelines(f"{k} {v}\n" for k, v in kv_pairs)
            
            # Write the number of queries
            infile.write(f"{len(queries)}\n")
            
            # Write each query
            infile.writelines(f"{q_key}\n" for q_key in queries)
            
            # Generate the output for the test case and write it to the output file
            output = execute_test_case((kv_pairs, queries))
            outfile.writelines(f"{result}\n" for result in output)


# Specify the file names
input_file = 'input.txt'
output_file = 'test_output.txt'

# Generate test cases and write to files
write_test_cases_and_output_to_file(input_file, output_file)

print(f"Test cases have been written to {input_file} and corresponding outputs to {output_file}.")