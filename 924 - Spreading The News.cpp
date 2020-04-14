//Using BFS. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ll e,n,t,a,s;
    cin>>e;
    vll AdjList[e];
    for(int i=0;i<e;i++)
    {
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>a;
            AdjList[i].push_back(a);
        }
    }
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>s;
        vll dist(e, LLONG_MAX); dist[s] = 0; // distance from source s to s is 0
        queue<int> q; q.push(s);
        if(AdjList[s].size()==0) cout<<0<<"\n";
        else
        {
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int j = 0; j < (int)AdjList[u].size(); j++) {
                    ll v = AdjList[u][j];
                    if (dist[v] == LLONG_MAX) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
            } } }
            sort(dist.begin(),dist.end());
            ll len=1,mx=0,f;
            for(int i=1;i<e;i++)
            {
                if(dist[i-1]==dist[i])
                {
                    len++;
                }
                else
                {
                    if(len>mx && dist[i-1]!=LLONG_MAX)
                    {
                        mx=len;
                        f=dist[i-1];
                    }
                    len=1;
                }
            }
            if(len>mx && dist[e-1]!=LLONG_MAX)
            {
                mx=len;
                f=dist[e-1];
            }
            if(f==0) f++;
            cout<<mx<<" "<<f<<"\n";
        }    
    }
}
