from random import randint as ri

for i in range(1,6):
    with open('%d.in'%i, 'wt') as FILE:
        n, q = 2**(2+i), min(200,2**(3+i))
        print(n,q,file=FILE)
        a = [ri(0,4*n) for x in range(n)]
        print(*a,file=FILE)
        for j in range(q):
            L, R = ri(1,n//2), ri(n//2,n)
            k = ri(1,R-L+1)
            print(L,R,k,file=FILE)

