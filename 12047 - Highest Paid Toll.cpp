//Using Dijkstra. Time-0.070s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc,n,m,s,t,p,u,v,c;
    cin>>tc;
    for(int i=0;i<tc;i++)
    {
        cin>>n>>m>>s>>t>>p;
        s--; t--;
        vector<pair<ll,ll> > AdjList[n],RevList[n];
        for(int i=0;i<m;i++)
        {
            cin>>u>>v>>c;
            u--; v--;
            AdjList[u].push_back(make_pair(v,c));
            RevList[v].push_back(make_pair(u,c));
        }
        ll dist[n];
        for(int i=0;i<n;i++)
        {
            dist[i]=LLONG_MAX;
        }
        dist[s] = 0;
        priority_queue< pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq; pq.push(make_pair(0, s));
        while (!pq.empty())
        {
            pair<ll,ll> front = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
            int d = front.first, u = front.second;
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
        ll dist1[n];
        for(int i=0;i<n;i++)
        {
            dist1[i]=LLONG_MAX;
        }
        dist1[t] = 0;
        priority_queue< pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq1; pq1.push(make_pair(0, t));
        while (!pq1.empty())
        {
            pair<ll,ll> front = pq1.top(); pq1.pop(); // greedy: get shortest unvisited vertex
            int d = front.first, u = front.second;
            if (d > dist1[u]) continue;
            for (int j = 0; j < (int)RevList[u].size(); j++)
            {
                pair<ll,ll> v = RevList[u][j];
                if (dist1[u] + v.second < dist1[v.first])
                {
                    dist1[v.first] = dist1[u] + v.second; // relax operation
                    pq1.push(make_pair(dist1[v.first], v.first));
                }
            }
        }
        ll ans=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<AdjList[i].size();j++)
            {
                pair<ll,ll> v=AdjList[i][j];
                if((dist[i]!=LLONG_MAX) && (dist1[v.first]!=LLONG_MAX) && (dist[i]+v.second+dist1[v.first]) <= p)
                {
                    ans=max(ans,v.second);
                }
            }
        }
        cout<<ans<<"\n";
    }
}    
