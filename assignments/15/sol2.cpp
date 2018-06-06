#include <stdio.h>

const int N = 20;

int a[N][N];
short prev[N][1<<N];
short ans[N];

int main()
{
	int n,m;
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
			a[i][j]--;
		}

	for(int i = 0; i < m; i++)
		prev[0][1<<a[0][i]] = i+1;

	for(int i = 1; i < n; i++)
		for(short j = 0; j < m; j++)
			for(int k = 0; k < (1<<N); k++)
				if( !(k&(1<<a[i][j])) && prev[i-1][k] && !prev[i][k | (a[i][j])] )
					prev[i][k | (1<<a[i][j])] = j+1;
			

	int cur = (1<<n)-1;
	for(int i = n-1; i >= 0; i--)
	{
		ans[i] = prev[i][cur];
		cur ^= 1<<a[i][ans[i]-1];
	}

	for(int i = 0; i < n; i++)
		printf(i == n-1 ? "%d\n" : "%d ", (int)ans[i]);

	return 0;
}
