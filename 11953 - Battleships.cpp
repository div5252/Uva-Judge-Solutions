// Using floodfill. Time-0.010s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int dr[] = {1,0,0,-1}; 
int dc[] = {0,1,-1,0};  
char a[101][101];
ll n;
void dfs(ll i, ll j)
{
    if(i >= n || j >= n || i < 0 || j < 0)
        return;
    if(a[i][j]=='.') return;
    a[i][j]='.';
    for(int k=0;k<4;k++)
    {
        dfs(i+dr[k],j+dc[k]);
    }
}
int main()
{
    ll t,ans;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cout<<"Case "<<i+1<<": ";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
        ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]=='x')
                {
                    ans++;
                    dfs(i,j);
                }
            }
        }
        cout<<ans<<"\n";
    }
}
