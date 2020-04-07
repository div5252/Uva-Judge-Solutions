//Using toposort. Time-0.790s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

ll n,m,flag;
vll AdjList[1000000];
ll visit[1000000];
vll ts;
void graphCheck(ll u) { // DFS for checking graph edge properties
    visit[u] = 2; // color u as EXPLORED instead of VISITED
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        if (visit[AdjList[u][j]] == 0) { // Tree Edge, EXPLORED->UNVISITED
            graphCheck(AdjList[u][j]);
        }
        else if (visit[AdjList[u][j]] == 2) { // EXPLORED->EXPLORED
            flag=1;
        }
    }
    visit[u] = 1; // after recursion, color u as VISITED (DONE)
    ts.push_back(u);
}
int main()
{
    ll a,b;
    while(cin>>n>>m)
    {
        if(n==0 && m==0) break;
        ts.clear();
        for(int i=0;i<n;i++)
        {
            visit[i]=0;
            AdjList[i].clear();
        }
        flag=0;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            AdjList[a-1].push_back(b-1);
        }
        for(int i=0;i<n;i++)
        {
            if(visit[i]==0)
            {
                graphCheck(i);
            }
        }
        if(flag==1) cout<<"IMPOSSIBLE\n";
        else
        {
            for(int i=ts.size()-1;i>=0;i--)
            {
                cout<<ts[i]+1<<"\n";
            }
        }
    }
}
