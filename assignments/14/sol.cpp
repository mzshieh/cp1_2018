#include<cstdio>
#include<algorithm>
using namespace std;

bool d[2][101][10001];
int n, k, ans=10000, sum;

int main()
{
	scanf("%d%d", &n, &k);
	d[1][0][0]=true;
	for (int i = 0, w; i < n; i++)
	{
	    scanf("%d", &w);
	    sum+=w;
        for(int j=0; j<101; j++)
            for(int l=10000; l>=0; l--)
            {
                d[i&1][j][l]=d[i&1^1][j][l];
                if(j-1>=0 && l-w>=0)
                    d[i&1][j][l]=d[i&1][j][l]||d[i&1^1][j-1][l-w];
                if(i==n-1 && abs(j-(n-j))<=k && d[i&1][j][l])
                        ans=min(ans, abs(l-(sum-l)));
            }
	}
	printf("%d\n", ans);
}
