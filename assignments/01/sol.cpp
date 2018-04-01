#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
typedef long double llf;
typedef long long lld;
char buf[1<<20];

lld sq(lld x)
{
    return round(sqrt((llf)x));
}

bool check(lld x)
{
    return x==sq(x)*sq(x);
}

bool remove(multiset<lld>& S, lld x)
{
    auto it=S.find(x);
    
    if( it==S.end() )
        return false;
    
    S.erase(it);
    return true;
}

bool solve(vector<int>& ans, multiset<lld>& S)
{
    ans.assign(1, sq(*S.rbegin()));
    
    while( !S.empty() )
    {
        lld x=*S.rbegin()/ans[0];
        
        for(int i=ans.size()-1; i>0; i--)
            if( !remove(S, x*ans[i]) )
                return false;
        
        ans.push_back(x);
        
        for(int i=ans.size()-1; i>0; i--)
            if( !remove(S, x*ans[i]) )
                return false;
    }
    
    if( !S.empty() )
        return false;
    
    return true;
}

bool solve()
{
    if( scanf("%[^\n] ", buf)!=1 )
        return false;
    
    multiset<lld> S;
    
    for(const char *p=strtok(buf, " "); p!=NULL; p=strtok(NULL, " "))
        S.insert(atoll(p));
    
    vector<int> ans;
    
    if( !solve(ans, S) )
        printf("No\n");
    else
    {
        printf("Yes\n");
        
        for(int i=ans.size()-1; i>0; i--)
            printf(i==1 ? "%d\n" : "%d ", ans[i]);
    }
    
    return true;
}

int main()
{
    while( solve() );
}
