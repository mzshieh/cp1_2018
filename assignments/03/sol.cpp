#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

char s[10000];
char* name[]= {"Alice", "Bob", "Carol"};

void rem(vector<int> &v)
{
    for(int i=0; i<v.size(); i++)
        for(int j=i+1; j<v.size(); j++)
            if(v[i]==v[j])
            {
                v.erase(v.begin()+j);
                v.erase(v.begin()+i);
                i--;
                break;
            }
}

int main()
{
    int T;
    for(scanf("%d", &T); T>0; T--)
    {
        vector<int> v[3], r[3];
        int now=0;
        for(int i=0, x; i<3; i++)
        {
            scanf("%d", &x);
            v[i].resize(x);
            for(int j=0; j<x; j++)
            {
                scanf("%s", s);
                if(s[0]=='J')
                    v[i][j]=-1, now=i;
                else
                    sscanf(s, "%d", &v[i][j]);
            }
            rem(v[i]);
        }
        for(int i=0, x; i<3; i++)
        {
            scanf("%d", &x);
            r[i].resize(x);
            for(int j=0; j<x; j++)
                scanf("%d", &r[i][j]);
        }
        int p=0;
        for(; p<=100000;)
        {
            if(min(min(v[0].size(), v[1].size()), v[2].size())==0)
            {
                printf("%s\n", name[now]);
                break;
            }
            p++;
            for(int i=0; i<3; i++)
            {
                int j=(i+1)%3;
                int t=(r[i][(p+r[i].size()-1)%r[i].size()]-1)%v[j].size();
                if(v[j][t]==-1)
                    now=i;
                v[i].push_back(v[j][t]);
                v[j].erase(v[j].begin()+t);
                rem(v[i]);
                if(min(v[i].size(), v[j].size())==0)
                    break;
            }
        }
        if(p>100000)
            printf("Good Game\n");
    }
}
