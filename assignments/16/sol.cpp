#include<cstdio>

typedef long long lld;

const lld P = 1000000007, N = 20;
int a[N][N + 1], n, m;
lld d[1 << N]={1};

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0, t; j < m; j++)
			scanf("%d", &t), a[i][t]++;
	for (int b = 1; b < 1 << n; b++)
		for (int i = 0; i < n; i++)
			if (b & 1 << i)
				d[b] = (d[b] + a[i][__builtin_popcount(b)] * d[b ^ 1 << i]) % P;
	printf("%lld\n", d[(1 << n) - 1]);
}
