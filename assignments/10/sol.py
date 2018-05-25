def gcd(a, b):
	return a if b == 0 else gcd(b, a%b)
def lcm(a, b):
	return a*b/gcd(a, b)
def solve(a, b, c):
	return 1 if lcm(a, b) == c else solve(a, b*c/lcm(a,b), c)*c/lcm(a,b)
q = int(raw_input())
for i in range(q):
	a, c = map(int, raw_input().split(" "))
	print -1 if c%a != 0 else solve(a,1,c)
