#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long lld;

const int N=100000;

struct bit
{
    vector<lld> a;
    bit(): a(N+1) {}
    void add(int x, lld val)
    {
        for(; x<=N; x+=x&-x)
            a[x]+=val;
    }
    lld get(int x)
    {
        lld res=0;
        for(; x>=1; x-=x&-x)
            res+=a[x];
        return res;
    }
};

int main()
{
        int T;
        for(scanf("%d", &T); T>0; T--)
        {
            int n;
            scanf("%d", &n);
            vector<int> a(n);
            for(int i=0; i<n; i++)
                scanf("%d", &a[i]);
            vector<vector<lld>> q;
            for(int i=n-1, minval=N; i>=0; i--)
            {
                if(minval<=a[i])
                    continue;
                if(a[i]+1<minval)
                {
                    q.push_back({i, 0, a[i]+1, minval-1, a[i]});
                    q.push_back({i, 1, a[i]+1, (lld)-a[i]*a[i]});
                    q.push_back({i, 1, minval, (lld)a[i]*a[i]});
                }
                q.push_back({i, 1, minval, (lld)a[i]*(minval-a[i])});
                minval=a[i];
            }
            bit b, b2;
            lld ans=0;
            sort(q.begin(), q.end());
            for(int i=0, p=0; i<n; i++)
            {
                for(; p<q.size() && q[p][0]==i; p++)
                {
                    if(q[p][1]==0)
                    {
                        ans+=b.get(q[p][3])*q[p][4];
                        ans-=b.get(q[p][2]-1)*q[p][4];
                    }
                    else
                    {
                        ans+=b2.get(N)*q[p][3];
                        ans-=b2.get(q[p][2]-1)*q[p][3];
                    }
                }
                b.add(a[i], a[i]);
                b2.add(a[i], 1);
            }
            printf("%lld\n", ans);
        }
}
