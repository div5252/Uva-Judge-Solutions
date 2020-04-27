//Using Bellman Ford. Time-0.020s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t,n,m,x,y,c;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>m;
        vector<pair<ll,ll> > AdjList[n];
        for(int i=0;i<m;i++)
        {
            cin>>x>>y>>c;
            AdjList[x].push_back(make_pair(y,c));
        }
        ll dist[n];
        for(int i=0;i<n;i++)
        {
            dist[i]=LLONG_MAX;
        }
        dist[0] = 0;
        for (int i = 0; i < n - 1; i++) // relax all E edges V-1 times
            for (int u = 0; u < n; u++) // these two loops = O(E), overall O(VE)
                for (int j = 0; j < (int)AdjList[u].size(); j++) {
                    pair<ll,ll> v = AdjList[u][j]; // record SP spanning here if needed
                    dist[v.first] = min(dist[v.first], dist[u] + v.second); // relax
                }
        bool hasNegativeCycle = false;
        for (int u = 0; u < n; u++) // one more pass to check
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                pair<ll,ll> v = AdjList[u][j];
                if (dist[v.first] > dist[u] + v.second) // if this is still possible
                    hasNegativeCycle = true; // then negative cycle exists!
            }
        if(hasNegativeCycle) cout<<"possible";
        else cout<<"not possible";
        cout<<"\n";
    }
}    
