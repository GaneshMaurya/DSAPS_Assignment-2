import math

n = 10**5  # maximum number of elements
p = 0.001   # false positive rate (1%)

# Calculate m (size of bit array)
m = int(-n * math.log(p) / (math.log(2) ** 2))

# Calculate k (number of hash functions)
k = int((m / n) * math.log(2))

print(f"Optimal size of bit array (m): {m} bits")
print(f"Optimal number of hash functions (k): {k}")
