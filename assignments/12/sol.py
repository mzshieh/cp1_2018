ans = [0] * 1000001
ans[1] = 1
MOD = 10**9 + 7
for i in range(2,1000001):
    ans[i] = (1 + ans[i-1] + ans[i-2])%MOD

n = int(input())
for _ in range(n):
    x = int(input())
    print(ans[x])
