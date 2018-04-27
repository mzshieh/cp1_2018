#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long lld;

const int N = 1<<16;
const int K = 1<<12;
lld x[N] = {0};


vector<lld> solve(const vector<lld> &l, const vector<lld> &r)
{
	if( l.size() <= K )
	{
		vector<lld> ans(l.size()<<1);

		for(int i = 0; i < l.size(); i++)
			for(int j = 0; j < r.size(); j++)
				ans[i+j] += l[i]*r[j];
		return ans;
	}
	else
	{
		vector<lld> ll, lr, rl, rr;

		int m = l.size()/2;

		ll.assign(l.begin(), l.begin()+m);
		lr.assign(l.begin()+m, l.end());
		rl.assign(r.begin(), r.begin()+m);
		rr.assign(r.begin()+m, r.end());

		vector<lld> ls(lr);
		vector<lld> rs(rr);

		for(int i = 0; i < m; i++)
		{
			ls[i] += ll[i];
			rs[i] += rl[i];
		}

		vector<lld> lrs = solve(ls, rs);
		ll = solve(ll, rl);
		rr = solve(lr, rr);

		vector<lld> ans(l.size()*2);

		for(int i = 0; i < l.size(); i++)
		{
			ans[i+2*m] += rr[i];
			ans[i+m] += lrs[i]-ll[i]-rr[i];
			ans[i] += ll[i];
		}

		return ans;
	}
}


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	vector<lld> w1(N, 0), w2(N, 0);

	for(int i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		w1[t]++;
		w2[t]++;
	}

	vector<lld> ans = solve(w1, w2);
	ans.resize(N<<1);

	for(int i = 0; i < N; i++)
		ans[i*2] -= w1[i];

	for(int i = 0; i < m; i++)
	{
		int p;
		scanf("%d", &p);

		printf("%lld\n", ans[p]/2);
	}

	return 0;
}
