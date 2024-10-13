import subprocess
import threading
import time

def execute_cpp_program():
    # Function to run the C++ program using subprocess
    try:
        # Start the C++ program (ensure the C++ executable is built beforehand)
        result = subprocess.run(["./a.exe"], capture_output=True, text=True)
        # Print the output of the C++ program (optional)
        print("Program Output:\n", result.stdout)
        # Print any errors (if exist)
        if result.stderr:
            print("Program Errors:\n", result.stderr)
    except Exception as e:
        print(f"Error running C++ program: {e}")

def main():
    # Measure start time
    start_time = time.time()

    # Create a thread to execute the C++ program
    cpp_thread = threading.Thread(target=execute_cpp_program)

    # Start the thread
    cpp_thread.start()

    # Wait for the thread to complete
    cpp_thread.join()

    # Measure end time
    end_time = time.time()

    # Calculate total execution time
    execution_time = end_time - start_time
    print(f"Execution Time: {execution_time:.4f} seconds")

if __name__ == "__main__":
    main()