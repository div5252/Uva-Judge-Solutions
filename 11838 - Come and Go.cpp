//SCC. Time-0.050s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

vll AdjList[2001],dfs_num,dfs_low,visited,S;
ll dfsNumberCounter,numSCC;

void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    S.push_back(u); // stores u in a vector based on order of visitation
    visited[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ll v = AdjList[u][j];
        if (dfs_num[v] == -1)
            tarjanSCC(v);
        if (visited[v])   // condition for update
            dfs_low[u] = min(dfs_low[u], dfs_low[v]); }
            
    if (dfs_low[u] == dfs_num[u]) {     // if this is a root (start) of an SCC
        ++numSCC;    // this part is done after recursion
        while (1) {
            int v = S.back(); S.pop_back(); visited[v] = 0;
            if (u == v) break; }
} }
int main()
{
    ll n,m,v,w,p;
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
        visited.assign(n, 0); 
        numSCC=0;
        for(int i=0;i<m;i++)
        {
            cin>>v>>w>>p;
            v--; w--;
            if(p==1)
            {
                AdjList[v].push_back(w);
            }
            else
            {
                AdjList[v].push_back(w);
                AdjList[w].push_back(v);   
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dfs_num[i]==-1)
            {
                tarjanSCC(i);
            }
        }
        if(numSCC==1) cout<<"1\n";
        else cout<<"0\n";
    }
}
