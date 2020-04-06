//Using dfs. Time-0.310s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

vll graph,sum;
vector<bool> visit;
ll dfs(ll u) 
{
    visit[u] = true;
    ll tot = 0;
    if(graph[u] != -1 && !visit[graph[u]])
        tot += 1 + dfs(graph[u]);
    visit[u] = false;
    return sum[u] = tot;
}
int main()
{
    ll t,n,ans,mx,a,b;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cout<<"Case "<<i+1<<": ";
        cin>>n;
        graph.assign(n,-1);
        sum.assign(n,-1);
        visit.assign(n,false);
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            graph[a-1]=b-1;
        }
        mx=0; ans=0;
        for(int i=0;i<n;i++)
        {
            if(sum[i]== -1) dfs(i);
            if(sum[i]>mx)
            {
                mx=sum[i];
                ans=i;
            }
        }
        cout<<ans+1<<"\n";
    }
}
