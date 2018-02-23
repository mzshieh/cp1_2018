n = int(input())
a = [int(x) for x in input().strip().split()]
ans = max(*a)
for i in range(n):
    for j in range(i+1, n+1):
        ans = max(ans, sum(a[i:j]))
print(ans)
