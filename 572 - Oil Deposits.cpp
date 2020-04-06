//Connected components. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int dr[] = {1,1,0,-1,-1,-1, 0, 1};  // trick to explore an implicit 2D grid
int dc[] = {0,1,1, 1, 0,-1,-1,-1};  // S,SE,E,NE,N,NW,W,SW neighbors
char ar[101][101];
ll m,n,visit[101][101];

void dfs(ll a,ll b)
{
    ll x,y;
    visit[a][b]=1;
    for(int i=0;i<8;i++)
    {
        x=a+dr[i];
        y=b+dc[i];
        if(x>=0 && x<m && y>=0 && y<n && !visit[x][y])
        {
            visit[x][y]=1;
            if(ar[x][y]=='@') dfs(x,y);
        }
    }
}
int main()
{
    ll ans;
    while(cin>>m>>n)
    {
        if(m==0) break;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>ar[i][j];
            }
        }
        memset(visit,0,sizeof(visit));
        ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visit[i][j])
                {
                    visit[i][j]=1;
                    if(ar[i][j]=='@')
                    {
                        ans++;
                        dfs(i,j);
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
}
