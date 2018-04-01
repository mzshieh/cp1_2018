#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
typedef long long lld;
const int N=1<<10;
char buf[N*100];
int r[N], c[N];

#define pos pair<int,int>
#define x first
#define y second

bool solve()
{
    if( feof(stdin) )
        return false;
    
    int n, row=0, col=0;
    
    for(int i=0; i<3; i++)
    {
        scanf("%[^\n] ", buf);
        n=strlen(buf);
    }
    
    n/=10;
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    map<lld, pos> M;
    
    for(int i=0; i<n; i++)
    {
        scanf("%s", buf);
        
        for(int j=0; j<n; j++)
        {
            lld x;
            sscanf(buf+j*10+1, "%lld", &x);
            M[x]={i, j};
        }
        
        scanf("%*s");
    }
    
    for(lld q; scanf("%lld", &q)==1; )
    {
        if( M.find(q)==M.end() )
            continue;
        
        row+=++r[ M[q].x ]==n;
        col+=++c[ M[q].y ]==n;
        printf("%d %d\n", row, col);
    }
    
    return true;
}

int main()
{
    while( solve() );
}
