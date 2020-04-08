//SCC. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

vll AdjList[30],dfs_num,dfs_low,visited,S;
ll dfsNumberCounter,numSCC;
map<string,ll> mp;
map<ll,string> rev;
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
        ll i=0;
        while (1) {
            i++;
            int v = S.back(); S.pop_back(); visited[v] = 0;
            if(i==1) cout<<rev[v];
            else cout<<", "<<rev[v];
            if (u == v) break; }
        cout<<"\n";    
} }
int main()
{
    ll n,m,t=0;
    string a,b;
    while(cin>>n>>m)
    {
        if(n==0 && m==0) break;
        t++;
        if(t!=1) cout<<"\n";
        cout<<"Calling circles for data set "<<t<<":\n";
        for(int i=0;i<n;i++)
        {
            AdjList[i].clear();
        }
        mp.clear(); rev.clear();
        dfsNumberCounter = 0; 
        dfs_num.assign(n, -1); 
        dfs_low.assign(n, 0);
        visited.assign(n, 0); 
        numSCC=0;
        ll j=0;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            if(mp.find(a)==mp.end())
            {
                mp.insert(make_pair(a,j));
                rev.insert(make_pair(j,a));
                j++;
            }
            if(mp.find(b)==mp.end())
            {
                mp.insert(make_pair(b,j));
                rev.insert(make_pair(j,b));
                j++;
            }
            AdjList[mp[a]].push_back(mp[b]);
            
        }
        for(int i=0;i<n;i++)
        {
            if(dfs_num[i]==-1)
            {
                tarjanSCC(i);
            }
        }
    }
}
