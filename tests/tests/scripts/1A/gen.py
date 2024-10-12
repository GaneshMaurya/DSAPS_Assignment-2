import sys
import random

T_MAX = int(sys.argv[1])
N_MAX = int(sys.argv[2])
Q_MAX = int(sys.argv[3])
KV_MAX = int(sys.argv[4])

t = random.randint(1, T_MAX)
print(t)

for _ in range(t):
    n = random.randint(1, N_MAX)
    print(n)

    kv = [f"{random.randint(1, KV_MAX)} {random.randint(1, KV_MAX)}" for _ in range(n)]
    print(*kv, sep='\n')

    q = random.randint(1, Q_MAX)
    print(q)
    kq = [random.randint(1, KV_MAX) for _ in range(q)]
    print(*kq, sep='\n')
