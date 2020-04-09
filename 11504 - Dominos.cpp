//First toposort, and then count the connected components. Time-0.190s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

vll AdjList[100000],dfs_num,ts,visit;

void dfs(int u) {
    dfs_num[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++) { // default DS: AdjList
        ll v = AdjList[u][j]; // v is a (neighbor, weight) pair
        if (dfs_num[v] == 0) // important check to avoid cycle
        dfs(v);
    }
}
void dfs2(int u) {
    visit[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ll v = AdjList[u][j];
        if (visit[v] == 0)
            dfs2(v);
    }
    ts.push_back(u);
}

int main()
{
    ll n,m,t,x,y,ans;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            AdjList[i].clear();
        }
        ts.clear();
        dfs_num.assign(n, 0); 
        visit.assign(n,0);
        for(int i=0;i<m;i++)
        {
            cin>>x>>y;
            AdjList[x-1].push_back(y-1);
            
        }
        for(int i=0;i<n;i++)
        {
            if(visit[i]==0)
            {
                dfs2(i);
            }
        }
        reverse(ts.begin(),ts.end());
        ans=0;
        for(int i=0;i<n;i++)
        {
            if(dfs_num[ts[i]]==0) 
            {
                dfs(ts[i]);
                ans++;
            }    
        }
        cout<<ans<<"\n";
    }
}
