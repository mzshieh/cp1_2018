#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long lld;

int n;
vector<int> w;
vector<vector<lld>> dp;//no, yes
vector<vector<int>> E;

void sol(int u)
{
	for (int v : E[u])
	{
		sol(v);
		dp[u][0] += max(dp[v][0], dp[v][1]);
		dp[u][1] += dp[v][0];
	}
	dp[u][1] += w[u];
}

void get(int u, vector<int> &ans, lld &sum, int t)
{
	if (t == 0)
		for (int v : E[u])
			get(v, ans, sum, 2);
	else if (t == 1)
	{
		ans.push_back(u);
		sum += w[u];
		for (int v : E[u])
			get(v, ans, sum, 0);
	}
	else
		get(u, ans, sum, dp[u][1] >= dp[u][0]);
}

int main()
{
	scanf("%d", &n);
	w.resize(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	dp.assign(n + 1, vector<lld>(2, 0));
	E.assign(n + 1, vector<int>());
	for (int i = 1, u, v; i <= n - 1; i++)
	{
		scanf("%d%d", &u, &v);
		E[v].push_back(u);
		dp[u][0] = 1;
	}
	int s = 0;
	for (int i = 1; i <= n; i++)
		if (dp[i][0] == 0)
			s = i;
		else
			dp[i][0] = 0;
	sol(s);

	vector<int> ans;
	lld sum = 0;
	get(s, ans, sum, 2);//no, yes, x
	printf("%lld\n", sum);
	for (int i = 0; i < ans.size(); i++)
		printf("%d%s", ans[i], i + 1 == ans.size() ? "\n" : " ");
}
