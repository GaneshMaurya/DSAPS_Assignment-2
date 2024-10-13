import random
import string

def generate_random_string(length):
    """Generate a random string of fixed length."""
    return ''.join(random.choices(string.ascii_lowercase, k=length))

def generate_test_cases(num_tests, max_strings_per_test, max_string_length, max_total_length):
    """Generate test cases based on the provided constraints."""
    total_length = 0
    test_cases = []

    for _ in range(num_tests):
        if total_length >= max_total_length:
            break  # Stop if total length exceeds limit
        
        # Randomly decide the number of strings for this test case
        n = random.randint(1, max_strings_per_test)
        strings = set()  # To avoid duplicates in the same test case
        
        while len(strings) < n:
            # Generate random string length (1 to max_string_length)
            string_length = random.randint(1, max_string_length)
            random_string = generate_random_string(string_length)

            # Ensure the total length doesn't exceed the limit
            if total_length + len(random_string) > max_total_length:
                continue
            
            strings.add(random_string)
            total_length += len(random_string)
        
        test_cases.append((n, strings))
    
    return test_cases

def main():
    # Configuration for test cases
    t = 2  # Number of test cases
    max_n = 10**5  # Maximum number of strings per test case
    max_length_per_string = 10**4  # Maximum length of each string
    max_total_length = 2 * 10**8  # Total length constraint across all test cases

    test_cases = generate_test_cases(t, max_n, max_length_per_string, max_total_length)

    # Write the generated test cases to test_input.txt
    with open('input.txt', 'w') as input_file:
        input_file.write(f"{t}\n")  # Print number of test cases
        for n, strings in test_cases:
            input_file.write(f"{n}\n")  # Print the number of strings for this test case
            for s in strings:
                input_file.write(f"{s}\n")  # Print each string

    # Generate expected output for the test cases (for testing purposes)
    expected_output = []
    for n, strings in test_cases:
        seen = set()
        output = []
        for s in strings:
            if s in seen:
                output.append('1')  # Previously encountered
            else:
                output.append('0')  # Not encountered
                seen.add(s)
        expected_output.append('\n'.join(output))

    # Write the expected output to test_output.txt
    with open('test_output2a.txt', 'w') as output_file:
        for output in expected_output:
            output_file.write(f"{output}\n")

if __name__ == "__main__":
    main()