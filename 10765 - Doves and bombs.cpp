//Articulation Points. Time-0.010s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

vll AdjList[10005],dfs_num,dfs_low,dfs_parent,articulation_vertex;
ll dfsNumberCounter,dfsRoot,rootChildren;

void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ll v = AdjList[u][j];
        if (dfs_num[v] == -1) { // a tree edge
            dfs_parent[v] = u;
            if (u == dfsRoot) rootChildren++; // special case if u is a root
            articulationPointAndBridge(v);
            if (dfs_low[v] >= dfs_num[u] && u!=dfsRoot) // for articulation point
                articulation_vertex[u] += 1; // store this information first
            dfs_low[u] = min(dfs_low[u], dfs_low[v]); // update dfs_low[u]
        }
        else if (v != dfs_parent[u]) // a back edge and not direct cycle
            dfs_low[u] = min(dfs_low[u], dfs_num[v]); // update dfs_low[u]
} }
int main()
{
    ll a,b,n,m,t=0;
    while(cin>>n>>m)
    {
        if(n==0 && m==0) break;
        for(int i=0;i<n;i++)
        {
            AdjList[i].clear();
        }
        dfsNumberCounter = 0; 
        dfs_num.assign(n, -1); 
        dfs_low.assign(n, 0);
        dfs_parent.assign(n, 0); 
        articulation_vertex.assign(n, 0);
        while(cin>>a>>b)
        {
            if(a==-1 && b==-1) break;
            AdjList[a].push_back(b);
            AdjList[b].push_back(a);
        }
        for(int i=0;i<n;i++)
        {
            if(dfs_num[i]==-1)
            {
                dfsRoot = i; 
                rootChildren = 0; 
                articulationPointAndBridge(i);
                if(rootChildren>1) articulation_vertex[dfsRoot]=1;
            }
        }
        vector<pair<ll,ll> > ans;
        for(int i=0;i<n;i++)
        {
            articulation_vertex[i]++;
            ans.push_back(make_pair(-articulation_vertex[i],i));
        }
        sort(ans.begin(),ans.end());
        ll j=0;
        while(j<min(m,n))
        {
            cout<<ans[j].second<<" "<<-ans[j].first<<"\n";
            j++;
        }
        cout<<"\n";
    }
}
