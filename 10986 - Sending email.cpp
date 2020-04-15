//Using Dijkstra. Time-0.190s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int di[]={-1,1,0,0,0,0};
int dj[]={0,0,-1,1,0,0};
int dk[]={0,0,0,0,-1,1};

int main()
{
    ll N,n,m,s,t,a,b,w;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cout<<"Case #"<<i+1<<": ";
        cin>>n>>m>>s>>t;
        vector<pair<ll,ll> > AdjList[n];
        for(int i=0;i<m;i++)
        {
            cin>>a>>b>>w;
            AdjList[a].push_back(make_pair(b,w));
            AdjList[b].push_back(make_pair(a,w));
        }
        ll dist[n];
        for(int i=0;i<n;i++)
        {
            dist[i]=LLONG_MAX;
        }
        dist[s]=0;
        priority_queue< pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq; pq.push(make_pair(0, s));
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
        if(dist[t]==LLONG_MAX) cout<<"unreachable\n";
        else cout<<dist[t]<<"\n";
        
    }
}
