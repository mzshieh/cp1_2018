#include<cstdio>

const int N = 20;

int a[N][N + 1], ans[N];
int d[1 << N], e[1 << N];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 1, t; j <= m; j++)
		{
			scanf("%d", &t);
			a[i][t] = j;
		}
	d[0] = 1;
	for (int b = 1; b < 1 << n; b++)
	{
		int k = 0;
		for (int i = 0; i < n; i++)
			if (b & 1 << i)
				k++;
		for (int i = 0; i < n; i++)
			if (b & 1 << i && a[i][k] && d[b ^ 1 << i])
				d[b] = i + 1, e[b] = a[i][k];
	}
	for (int b = (1 << n) - 1; b > 0; b ^= 1 << d[b] - 1)
		ans[d[b] - 1] = e[b];
	for (int i = 0; i < n; i++)
		printf("%d%s", ans[i], i + 1 == n ? "\n" : " ");
}
