//Using BFS. Time-0.400s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};

int main()
{
    ll r,c,n,b,a1,a2,sr,sc,er,ec;
    while(cin>>r>>c)
    {
        if(r==0 && c==0) break;
        ll bomb[r][c]={};
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a1>>b;
            for(int j=0;j<b;j++)
            {
                cin>>a2;
                bomb[a1][a2]=1;
            }
        }
        cin>>sr>>sc>>er>>ec;
        ll dist[r][c];
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                dist[i][j]=LLONG_MAX;
            }
        }
        dist[sr][sc] = 0;
        queue<pair<ll,ll> > q; 
        q.push(make_pair(sr,sc));
        while (!q.empty()) {
            pair<ll,ll> u = q.front(); 
            q.pop();
            for(int i=0;i<4;i++)
            {
                if(dist[u.first+dr[i]][u.second+dc[i]]==LLONG_MAX && bomb[u.first+dr[i]][u.second+dc[i]]==0 && u.first+dr[i]<r && u.first+dr[i]>=0 && u.second+dc[i]<c && u.second+dc[i]>=0)
                {
                    dist[u.first+dr[i]][u.second+dc[i]]=dist[u.first][u.second]+1;
                    q.push(make_pair(u.first+dr[i],u.second+dc[i]));
                }
            }
        }
        cout<<dist[er][ec]<<"\n";
    }
}
