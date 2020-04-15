//Using Dijkstra. Time-1.080s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};

int main()
{
    ll t,n,m;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>m;
        ll w[n][m],dist[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>w[i][j];
                dist[i][j]=LLONG_MAX;
            }
        }
        dist[0][0] = w[0][0];
        priority_queue< pair<ll,pair<ll,ll> >, vector<pair<ll,pair<ll,ll> > >, greater<pair<ll,pair<ll,ll> > > > pq; 
        pq.push(make_pair(0, make_pair(0,0)));
        while (!pq.empty())
        {
            pair<ll,pair<ll,ll> > front = pq.top(); 
            pq.pop(); // greedy: get shortest unvisited vertex
            ll d = front.first, u1 = front.second.first, u2=front.second.second;
            if (d > dist[u1][u2]) continue;
            for (int j = 0; j < 4; j++)
            {
                ll v1=u1+dr[j];
                ll v2=u2+dc[j];
                if (v1>=0 && v1<n && v2>=0 && v2<m)
                {
                    if(dist[u1][u2] + w[v1][v2] < dist[v1][v2])  
                    {
                        dist[v1][v2] = dist[u1][u2] + w[v1][v2]; // relax operation
                        pq.push(make_pair(dist[v1][v2], make_pair(v1,v2)));
                    }    
                }
            }
        }
        cout<<dist[n-1][m-1]<<"\n";
    }
}
