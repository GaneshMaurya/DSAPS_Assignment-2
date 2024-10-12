import sys
import random

T_MAX = int(sys.argv[1])
N_MAX = int(sys.argv[2])
KV_MAX = int(sys.argv[3])

t = random.randint(1, T_MAX)
print(t)

for _ in range(t):
    n = random.randint(1, N_MAX)
    print(n)

    for _ in range(n):
        type = random.randint(0, 1)
        k = random.randint(1, KV_MAX)
        if type == 0:
            v = random.randint(1, KV_MAX)
            print(type, k, v)
        else:
            print(type, k)
