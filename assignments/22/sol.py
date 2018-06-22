input()
ans=0
for _ in input().split():
    ans^=len(bin(int(_)))-2
print('win' if ans==0 else 'lose')
