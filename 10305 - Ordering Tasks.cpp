//Using toposort. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

vector<vll> AdjList;
vll ts;
ll visit[101];
void dfs2(int u) { // different function name compared to the original dfs
    visit[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        if (!visit[AdjList[u][j]])
            dfs2(AdjList[u][j]);
    }
    ts.push_back(u); 
} 
int main()
{
    ll n,m,a,b;
    while(cin>>n>>m)
    {
        if(n==0 && m==0) break;
        AdjList.reserve(n);
        fill(visit,visit+n,0);
        ts.clear();
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            AdjList[a-1].push_back(b-1);
        }
        for(int i=0;i<n;i++)
        {
            if(!visit[i]) dfs2(i);
        }
        cout<<ts[ts.size()-1]+1;
        for(int i=ts.size()-2;i>=0;i--)
        {
            cout<<" "<<ts[i]+1;
        }
        cout<<"\n";
    }
}
