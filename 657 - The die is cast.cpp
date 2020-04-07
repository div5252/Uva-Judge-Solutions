//Using floodfill. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int dr[] = {1,0,0,-1}; 
int dc[] = {0,1,-1,0};  
char a[51][51];
ll w,h,cnt;
void dfs1(ll i,ll j)
{
    if(i >= h || j >= w || i < 0 || j < 0)  return;
    if(a[i][j]!='X') return;
    a[i][j]='*';
    for(int k=0;k<4;k++)
    {
        dfs1(i+dr[k],j+dc[k]);
    }
}
void dfs(ll i, ll j)
{
    if(i >= h || j >= w || i < 0 || j < 0)  return;
    if(a[i][j]=='.') return;
    if(a[i][j]=='X')
    {
        cnt++;
        dfs1(i,j);
    }
    a[i][j]='.';
    for(int k=0;k<4;k++)
    {
        dfs(i+dr[k],j+dc[k]);
    }
}
int main()
{
    ll t=0;
    while(cin>>w>>h)
    {
        if(w==0 && h==0) break;
        t++;
        cout<<"Throw "<<t<<"\n";
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                cin>>a[i][j];
            }
        }
        vll ans;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(a[i][j]!='.')
                {
                    cnt=0;
                    dfs(i,j);
                    ans.push_back(cnt);
                }
            }
        }
        sort(ans.begin(),ans.end());
        cout<<ans[0];
        for(int i=1;i<ans.size();i++)
        {
            cout<<" "<<ans[i];
        }
        cout<<"\n\n";
    }
}
