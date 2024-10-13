import random
import string

def generate_string(length):
    return ''.join(random.choice(string.ascii_lowercase) for _ in range(length))

def generate_test_case(test_case_number, num_queries):
    test_case_input = []
    test_case_output = []

    # Initialize a dictionary to store unique strings
    unique_strings = {}

    for _ in range(num_queries):
        query_type = random.choice([0, 1])  # Randomly choose between put (0) and get (1)
        
        if query_type == 0:  # put operation
            i = random.randint(1, 10**18)
            # Ensure unique string for the same key
            while True:
                s = generate_string(random.randint(1, 10**2))  # String length between 1 and 100
                if s not in unique_strings.values():
                    unique_strings[i] = s
                    break
            test_case_input.append(f"0 {i} {s}")
            test_case_output.append("")  # No output for put operation
        else:  # get operation
            q = random.choice(list(unique_strings.keys()) + [random.randint(1, 10**18)])
            test_case_input.append(f"1 {q}")
            if q in unique_strings:
                test_case_output.append(unique_strings[q])
            else:
                test_case_output.append("0")

    # Write input to file
    with open(f"test_input2b.txt", "w") as f:
        f.write(f"1\n{num_queries}\n")
        f.write("\n".join(test_case_input) + "\n")

    # Write output to file, only adding newline for type 1 queries
    with open(f"test_output2b.txt", "w") as f:
        for output in test_case_output:
            if output:  # Only write output for get queries
                f.write(output + "\n")

def main():
    random.seed(42)  # For reproducibility
    num_test_cases = 1  # Number of test cases

    for i in range(num_test_cases):
        num_queries = 10**3  # Total number of queries for this test case
        generate_test_case(i + 1, num_queries)

if __name__ == "__main__":
    main()