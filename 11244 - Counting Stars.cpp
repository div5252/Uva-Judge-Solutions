//Using flood fill. Time-0.010s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int dr[] = {1,1,0,-1,-1,-1, 0, 1};  // trick to explore an implicit 2D grid
int dc[] = {0,1,1, 1, 0,-1,-1,-1};  
char a[102][102];
ll visit[102][102]; 
ll r,c;
ll dfs(ll i, ll j)
{
    ll sx;
    if(i >= r || j >= c || i < 0 || j < 0)  return 0;
    if(a[i][j]=='.') return 0;
    if(visit[i][j]) return 0;
    visit[i][j]=1;
    sx=1;
    for(int k=0;k<8;k++)
    {
        sx+=dfs(i+dr[k],j+dc[k]);
    }
    return sx;
}
int main()
{
    ll ans;
    while(cin>>r>>c)
    {
        if(r==0 && c==0) break;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin>>a[i][j];
                visit[i][j]=0;
            }
        }
        ans=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(!visit[i][j] && a[i][j]=='*')
                {
                    ll temp=dfs(i,j);
                    if(temp==1) ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
}
