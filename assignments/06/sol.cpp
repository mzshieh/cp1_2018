#include<cstdio>
#include<vector>
#include<map>
using namespace std;

#define x first
#define y second
const int N=4;
char s[100];

int main()
{
    for(int l=1, r=1; l<=r; l++)
    {
        int P, W, maxh=0;
        scanf("%d%d", &P, &W);
        vector<vector<bool>> a(1, vector<bool>(W));
        map<int, vector<pair<int, int>>> b;
        b['L']= {{0, 2}, {0, 3}, {1, 2}, {2, 2}};
        b['J']= {{0, 2}, {0, 3}, {1, 3}, {2, 3}};
        b['O']= {{0, 2}, {0, 3}, {1, 2}, {1, 3}};
        b['I']= {{0, 3}, {1, 3}, {2, 3}, {3, 3}};
        b['Z']= {{0, 2}, {0, 3}, {1, 1}, {1, 2}};
        b['S']= {{0, 1}, {0, 2}, {1, 2}, {1, 3}};
        b['T']= {{0, 2}, {1, 1}, {1, 2}, {1, 3}};
        for(; P>0; P--)
        {
            scanf("%s", s);
            vector<pair<int, int>> &c=b[s[0]];
            int x, u=maxh, v=W-N;
            scanf("%s", &s);
            for(int i=0; s[i]; i++)
            {
                v+=s[i]=='>'?1:-1;
                for(pair<int, int> &pa: c)
                    if(v+pa.y<0 || v+pa.y>=W)
                    {
                        v-=s[i]=='>'?1:-1;
                        break;
                    }
            }
            a.resize(u+N, vector<bool>(W));
            while(u>0)
            {
                u--;
                bool ok=1;
                for(pair<int, int> &pa: c)
                    if(a[u+pa.x][v+pa.y])
                        ok=0;
                if(!ok)
                {
                    u++;
                    break;
                }
            }
            for(pair<int, int> &pa: c)
                a[u+pa.x][v+pa.y]=1;
            vector<pair<int, int>> d(a.size());
            for(int i=0; i<a.size(); i++)
            {
                for(bool x: a[i])
                    d[i].x+=x;
                d[i].y=(d[i].x==W)+(i==0?0:d[i-1].y);
            }
            for(int i=0; i<a.size(); i++)
            {
                if(d[i].x==W)
                    continue;
                for(int j=0; j<W; j++)
                    a[i-d[i].y][j]=a[i][j];
                d[i-d[i].y].x=-1;
            }
            maxh=0;
            for(int i=0; i<a.size(); i++)
                for(int j=0; j<W; j++)
                {
                    if(d[i].x!=-1)
                        a[i][j]=0;
                    else if(a[i][j])
                        maxh=i+1;
                }
        }
        printf("%d\n", maxh);
    }
}
