#include <stdio.h>
#include <set>
#include <string>

using namespace std;

const int N = 1000000+1;
char ans[N];
int has[N][26], n, l, cnt;
set<string> s;

bool solve(int cur = 0)
{
	if( cur == l )
		return s.find(ans) == s.end() || (cnt++ > n);
	else
	{
		bool res = false;
		for(int i = 0; !res && i < 26; i++)
			if( has[cur][i] )
			{
				ans[cur] = 'a'+i;
				res = solve(cur+1);
			}
		return res;
	}
}

int main()
{
	char tmp[N];
	scanf("%d %d", &n, &l);
	
	for(int i = 0; i < n; i++)
	{
		scanf("%s", tmp);

		for(int j = 0; j < l; j++)
			has[j][tmp[j]-'a'] = true;
		s.insert(tmp);
	}

	if( solve() && s.find(ans) == s.end() )
		puts(ans);
	else
		puts("-1");
	return 0;
}
