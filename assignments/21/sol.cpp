#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

pair<int, int> solve(const vector<vector<int>>& e, int n, int u, int v)
{
    vector<int> d(n+1), p;
    
    for(int i=0; i<2; i++)
    {
        p.assign(n+1, -1);
        d[u]=p[u]=p[v]=0;
        queue<int> Q;
        
        for(Q.push(u); !Q.empty(); Q.pop())
        {
            u=Q.front();
            
            for(int v : e[u])
            {
                if( p[v]<0 )
                {
                    p[v]=u;
                    d[v]=d[u]+1;
                    Q.push(v);
                }
            }
        }
    }
    
    for(int i=d[u]>>1; i>0; i--)
        u=p[u];
    
    return {u, d[u]};
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<int>> e(n+1);
    
    for(int i=1; i<n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    
    int x=1, y=1, p=n;
    
    for(int v=1; v<=n; v++)
        for(int u : e[v])
            if( u<v )
            {
                pair<int, int> l=solve(e, n, v, u);
                pair<int, int> r=solve(e, n, u, v);
                
                if( p>max(l.second, r.second) )
                    p=max(l.second, r.second), x=l.first, y=r.first;
            }
    
    printf("%d %d %d\n", x, y, p);
}
