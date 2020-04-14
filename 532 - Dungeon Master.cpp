//Using 3D-BFS. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int di[]={-1,1,0,0,0,0};
int dj[]={0,0,-1,1,0,0};
int dk[]={0,0,0,0,-1,1};

int main()
{
    ll l,r,c,sx,sy,sz,ex,ey,ez;
    while(cin>>l>>r>>c)
    {
        if(l==0 && r==0 && c==0) break;
        char ar[l][r][c];
        for(int i=0;i<l;i++)
        {
            for(int j=0;j<r;j++)
            {
                for(int k=0;k<c;k++)
                {
                    cin>>ar[i][j][k];
                    if(ar[i][j][k]=='S') 
                    {
                        sx=i; sy=j; sz=k;
                    }
                    if(ar[i][j][k]=='E')
                    {
                        ex=i; ey=j; ez=k;
                    }
                }
            }
        }
        queue<pair<pair<ll,ll>,ll> > q;
        q.push(make_pair(make_pair(sx,sy),sz));
        ll dist[l][r][c]={};
        dist[sx][sy][sz]=1;
        pair<pair<ll,ll>,ll> u,v;
        while(!q.empty())
        {
            u=q.front();
            q.pop();
            for(int i=0;i<6;i++)
            {
                v.first.first=u.first.first+di[i];
                v.first.second=u.first.second+dj[i];
                v.second=u.second+dk[i];
                if(ar[v.first.first][v.first.second][v.second]!='#' && dist[v.first.first][v.first.second][v.second]==0 && v.first.first>=0 && v.first.first<l && v.first.second>=0 && v.first.second<r && v.second>=0 && v.second<c)
                {
                    dist[v.first.first][v.first.second][v.second]=dist[u.first.first][u.first.second][u.second]+1;
                    q.push(v);
                }
            }
        }
        if(dist[ex][ey][ez]==0) cout<<"Trapped!\n";
        else cout<<"Escaped in "<<dist[ex][ey][ez]-1<<" minute(s).\n";
    }
}
