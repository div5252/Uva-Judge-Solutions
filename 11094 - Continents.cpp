// Using floodfill. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int dr[] = {1,0,0,-1}; 
int dc[] = {0,1,-1,0};  
char a[21][21],land;
ll visit[21][21]; 
ll m,n;
ll dfs(ll i, ll j)
{
    ll sx;
    if(j==n) j=0; 
    else if(j==-1) j=n-1;
    if(i >= m || j >= n || i < 0 || j < 0)  return 0;
    if(a[i][j]!=land) return 0;
    if(visit[i][j]) return 0;
    visit[i][j]=1;
    sx=1;
    for(int k=0;k<4;k++)
    {
        sx+=dfs(i+dr[k],j+dc[k]);
    }
    return sx;
}
int main()
{
    ll x,y,ans,temp;
    while(cin>>m>>n)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
                visit[i][j]=0;
            }
        }
        cin>>x>>y;
        land=a[x][y];
        dfs(x,y);
        ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visit[i][j] && a[i][j]==land)
                {
                    temp=dfs(i,j);
                    ans=max(ans,temp);
                }
            }
        }
        cout<<ans<<"\n";
    }
}
