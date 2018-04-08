#include<cstdio>
#include<cstdlib>
#include<cstring>
typedef long long lld;
const lld INF=1LL<<60;
int a[1<<20], n;

bool read()
{
    static char s[1<<22];
    
    if( scanf("%[^\n] ", s)==EOF )
        return false;
    
    n=0;
    
    for(const char* p=strtok(s, " "); p!=NULL; p=strtok(NULL, " "))
        a[n++]=atoi(p);
    
    return true;
}

bool check(lld x)
{
    for(int i=0; i<n && x>0; i++)
    {
        if( x<a[i] )
            x>>=1;
        else if( x>a[i] )
            x+=(a[i]+1)>>1;
    }
    
    return x;
}

lld solve()
{
    lld ans=-1;
    
    for(lld l=1, r=INF; l<r; )
    {
        lld m=(l+r)>>1;
        
        if( check(m) )
            r=ans=m;
        else
            l=m+1;
    }
    
    return ans;
}

int main()
{
    while( read() )
        printf("%lld\n", solve());
}
