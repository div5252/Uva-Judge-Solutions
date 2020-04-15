//Using Dijkstra. Time-0.000s
//Remember to reverse the graph as we are checking from the destination point.

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ll cc,n,e,t,m,a,b,w;
    cin>>cc;
    for(int i=0;i<cc;i++)
    {
        if(i!=0) cout<<"\n";
        cin>>n>>e>>t;
        e--;
        cin>>m;
        vector<pair<ll,ll> > AdjList[n];
        for(int i=0;i<m;i++)
        {
            cin>>a>>b>>w;
            a--; b--;
            AdjList[b].push_back(make_pair(a,w));
        }
        ll dist[n];
        for(int i=0;i<n;i++)
        {
            dist[i]=LLONG_MAX;
        }
        dist[e] = 0;
        priority_queue< pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq; 
        pq.push(make_pair(0, e));
        while (!pq.empty())
        {
            pair<ll,ll> front = pq.top(); 
            pq.pop(); // greedy: get shortest unvisited vertex
            ll d = front.first, u = front.second;
            if (d > dist[u]) continue;
            for (int j = 0; j < (int)AdjList[u].size(); j++)
            {
                pair<ll,ll> v = AdjList[u][j];
                if (dist[u] + v.second < dist[v.first])
                {
                    dist[v.first] = dist[u] + v.second; // relax operation
                    pq.push(make_pair(dist[v.first], v.first));
                }
            }
        }
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            if(dist[i]<=t) ans++;
        }
        cout<<ans<<"\n";
    }
}
