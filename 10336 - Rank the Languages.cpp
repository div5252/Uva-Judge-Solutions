//Using floodfill. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int dr[] = {1,0,0,-1}; 
int dc[] = {0,1,-1,0};  
char a[10000][10000];
ll w,h;
set<ll> s;
char dfs(ll i, ll j)
{
    if(i >= h || j >= w || i < 0 || j < 0)  return 'A';
    if(a[i][j]=='.') return 'A';
    ll lan=a[i][j];
    a[i][j]='.';
    for(int k=0;k<4;k++)
    {
        if(i+dr[k] < h && j+dc[k] < w && i+dr[k] >= 0 && j+dc[k] >= 0 && a[i+dr[k]][j+dc[k]]==lan)
        {
            dfs(i+dr[k],j+dc[k]);
        }
    }
    return lan;
}
int main()
{
    ll n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"World #"<<i+1<<"\n";
        cin>>h>>w;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                cin>>a[i][j];
                s.insert(a[i][j]);
            }
        }
        ll ans[26]={};
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(a[i][j]!='.')
                {
                    ans[dfs(i,j)-'a']--;
                }
            }
        }
        vector<pair<ll,ll> > v;
        for(int i=0;i<26;i++)
        {
            if(ans[i]!=0)
            {
                v.push_back(make_pair(ans[i],i));
            }
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            cout<<(char)(v[i].second+'a')<<": "<<-1*v[i].first<<"\n";
        }
    }    
}
