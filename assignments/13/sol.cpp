#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> w(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &w[i]);
	vector<bool> d(1, true);
	for (int i = 0; i < n; i++)
	{
		vector<bool> p(d.size() + w[i]);
		for (int j = p.size() - 1; j >= 0; j--)
		{
			if (j < d.size())
				p[j] = p[j] || d[j];
			if (j - w[i] >= 0)
				p[j] = p[j] || d[j - w[i]];
		}
		d.swap(p);
	}
	int ans = d.size() - 1;
	for (int i = 0; i < d.size(); i++)
		if (d[i])
		{
			int l = i, r = d.size() - 1 - i;
			ans = min(ans, max(l, r) - min(l, r));
		}
	printf("%d\n", ans);
}
