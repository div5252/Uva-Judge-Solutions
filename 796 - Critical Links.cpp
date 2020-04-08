//Bridges in graph. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

vll AdjList[101],dfs_num,dfs_low,dfs_parent,articulation_vertex;
ll dfsNumberCounter,dfsRoot,rootChildren;
vector<pair<ll,ll> >ans;

void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ll v = AdjList[u][j];
        if (dfs_num[v] == -1) { // a tree edge
            dfs_parent[v] = u;
            if (u == dfsRoot) rootChildren++; // special case if u is a root
            articulationPointAndBridge(v);
            if (dfs_low[v] >= dfs_num[u] && u!=dfsRoot) // for articulation point
                articulation_vertex[u] = 1; // store this information first
            if (dfs_low[v] > dfs_num[u]) // for bridge
            {
                if(u>v) ans.push_back(make_pair(v,u));
                else ans.push_back(make_pair(u,v));
            }        
            dfs_low[u] = min(dfs_low[u], dfs_low[v]); // update dfs_low[u]
        }
        else if (v != dfs_parent[u]) // a back edge and not direct cycle
            dfs_low[u] = min(dfs_low[u], dfs_num[v]); // update dfs_low[u]
} }
int main()
{
    ll a,b,d,n,t=0;
    char c1,c2;
    while(cin>>n)
    {
        t++;
        for(int i=0;i<n;i++)
        {
            AdjList[i].clear();
        }
        ans.clear();
        dfsNumberCounter = 0; 
        dfs_num.assign(n, -1); 
        dfs_low.assign(n, 0);
        dfs_parent.assign(n, 0); 
        articulation_vertex.assign(n, 0);
        for(int i=0;i<n;i++)
        {
            cin>>a>>c1>>b>>c2;
            for(int j=0;j<b;j++)
            {
                cin>>d;
                AdjList[a].push_back(d);
            }
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
        sort(ans.begin(),ans.end());
        cout<<ans.size()<<" critical links\n";
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i].first<<" - "<<ans[i].second<<"\n";
        }
        cout<<"\n";
    }
}
