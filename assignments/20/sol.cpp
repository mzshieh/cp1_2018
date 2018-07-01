#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;

const int K=10;
char s[100];
vector<vector<vector<int>>> ttt;

vector<int> go(const vector<int> &a, int x)
{
    vector<int> res=a;
    for(auto &t: ttt[x])
        for(int i=0; i<4; i++)
            res[t[(i+1)%4]]=a[t[i]];
    return res;
}

int sol(vector<int> v[])
{
    if(v[0]==v[1])
        return 0;
    map<vector<int>, int> M[2];
    queue<vector<int>> Q[2];
    for(int i=0; i<2; i++)
        {
            M[i][v[i]]=0;
            Q[i].push(v[i]);
        }
    for(int k=0; k<(K+1)/2; k++)
    {
        for(int i=0; i<2; i++)
        {
            for(; !Q[i].empty() && M[i][Q[i].front()]<=k; Q[i].pop())
            {
                auto a=Q[i].front();
                for(int x=0; x<ttt.size(); x++)
                {
                    auto b=go(a, x);
                    if(M[i].find(b)==M[i].end())
                    {
                        M[i][b]=M[i][a]+1;
                        Q[i].push(b);
                        if(M[i^1].find(b)!=M[i^1].end())
                        {
                            int res=M[i][b]+M[i^1][b];
                            return res<=K?res:-1;
                        }
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    ttt.push_back({{1, 5, 7, 3}, {2, 8, 6, 0}, {12, 9, 18, 15}, {13, 10, 19, 16}, {14, 11, 20, 17}});
    ttt.push_back({{45, 47, 53, 51}, {46, 50, 52, 48}, {36, 39, 42, 33}, {37, 40, 43, 34}, {38, 41, 44, 35}});
    ttt.push_back({{12, 14, 38, 36}, {13, 26, 37, 24}, {6, 15, 47, 35}, {7, 27, 46, 23}, {8, 39, 45, 11}});
    ttt.push_back({{19, 32, 43, 30}, {20, 44, 42, 18}, {17, 0, 33, 53}, {29, 1, 21, 52}, {41, 2, 9, 51}});
    ttt.push_back({{27, 16, 29, 40}, {15, 17, 41, 39}, {38, 8, 18, 53}, {26, 5, 30, 50}, {14, 2, 42, 47}});
    ttt.push_back({{10, 23, 34, 21}, {11, 35, 33, 9}, {0, 12, 45, 44}, {3, 24, 48, 32}, {6, 36, 51, 20}});
    for(int i=6; i<12; i++)
    {
        ttt.push_back(ttt[i-6]);
        for(auto &t: ttt[i])
            reverse(t.begin(), t.end());
    }

    vector<int> v[2];

    for(int i=0; i<9; i++)
        v[0].push_back(1);
    for(int i=0; i<3; i++)
        for(int j=2; j<=5; j++)
            for(int k=0; k<3; k++)
                v[0].push_back(j);
    for(int i=0; i<9; i++)
        v[0].push_back(6);

    int T;
    for(scanf("%d", &T); T>0; T--)
    {
        v[1].clear();
        for(int i=0; i<9; i++)
            for(int j=0, t; j<12; j++)
            {
                scanf("%1d", &t);
                if(t!=0)
                    v[1].push_back(t);
            }
        printf("%d\n", sol(v));
    }
}
