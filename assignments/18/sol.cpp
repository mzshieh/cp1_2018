#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct lca{
	const int H=17;
	int n;
	vector<int> h;
	vector<vector<int>> p;
	lca(const vector<vector<int>>& e) : n(e.size()-1), h(n+1, -1), p(H, vector<int>(n+1, -1)){
		p[0][1]=1; dfs(e, 1, 0);
		for(int i=1; i<H; i++) for(int j=1; j<=n; j++){
			p[i][j]=p[i-1][ p[i-1][j] ];
		}
	}
	void dfs(const vector<vector<int>>& e, int u, int d=0){
		h[u]=++d;
		for(const int& v : e[u]){
			if( h[v]>=0 ) continue;
			p[0][v]=u;
			dfs(e, v, d);
		}
	}
	int operator()(int u, int v) const{
		if( h[u]>h[v] ) swap(u, v);
		for(int i=0, d=h[v]-h[u]; d>0; d>>=1, i++)
			if( d&1 ) v=p[i][v];
		for(int i=0; u!=v; i++){
			for(; i>0 && p[i][u]==p[i][v]; i--);
			u=p[i][u], v=p[i][v];
		}
		return u;
	}
};

int main()
{
    int n, m;
    scanf("%d%d%*d", &n, &m);
    vector<vector<int>> e(n+1);
    
    for(int u=2; u<=n; u++)
    {
        int v;
        scanf("%d", &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    
    for(lca L(e); m>0; m--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        int p=L(x, y);
        int q=L(y, z);
        int r=L(z, x);
        int g=L(p, q);
        printf("%d\n", L.h[x]+L.h[y]+L.h[z]-L.h[p]-L.h[q]-L.h[r]+L.h[g]);
    }
}
