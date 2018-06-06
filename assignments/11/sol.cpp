#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>

using namespace std;

typedef long long lld;
typedef pair<int,int> _data;

#define val first
#define idx second

const int N = 100000+100;
const lld MOD = 1000000007;

_data a[N];
int d[N], b[N], o[N];
map<int, int> q;

struct BIT
{
	lld a[N];

	BIT()
	{
		memset(a, 0, sizeof(a));
	}

	void add(int p, lld v)
	{
		for(; p < N; p += p&-p)
			a[p] = (a[p] + v)%MOD;
	}

	lld query(int p)
	{
		lld ans = 0;
		for(; p > 0; p -= p&-p)
			ans = (ans + a[p])%MOD;
		return ans;
	}

	lld query(int l, int r)
	{
		return (query(r)-query(l-1)+MOD)%MOD;
	}

	void clear()
	{
		memset(a, 0, sizeof(a));
	}

}lbit, rbit;


int main()
{
	int T;
	for(scanf("%d", &T); T > 0; T--, lbit.clear(), rbit.clear())
	{
		int n;
		scanf("%d", &n);

		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i].val);
			a[i].idx = i;
			o[i] = a[i].val;
		}

		sort(a+1, a+1+n);

		for(int i = n; i >= 1; i--)
		{
			d[a[i].idx] = i;
			q[a[i].val] = i;
		}

		for(int i = 1; i <= n; i++)
			b[i] = q[o[i]];

		for(int i = 1; i <= n; i++)
		{
			lld dp = (lbit.query(b[i]-1)+1)%MOD;
			lbit.add(d[i], dp);
		}

		for(int i = n; i >= 1; i--)
		{
			lld dp = (rbit.query(b[i]-1)+1)%MOD;
			rbit.add(d[i], dp);
		}

		lld ans = 0;
		for(int i = 1; i <= n; i++)
			ans = (ans + (lbit.query(i,i)-1)*(rbit.query(i,i)-1))%MOD;

		printf("%lld\n", ans);
	}
	
	return 0;
}
