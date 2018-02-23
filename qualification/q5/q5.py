n, q = [int(x) for x in input().strip().split()]
a = [int(x) for x in input().strip().split()]
for _ in range(q):
    L, R, k = [int(x) for x in input().strip().split()]
    b = a[L-1:R]
    b.sort()
    print(b[k-1])
