//Using BFS. Time-0.010s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ll l,u,r,t=0;
    while(cin>>l>>u>>r)
    {
        if(l==0 && r==0 && u==0) break;
        t++;
        cout<<"Case "<<t<<": ";
        ll num[r];
        for(int i=0;i<r;i++)
        {
            cin>>num[i];
        }
        ll dist[10000];
        for(int i=0;i<10000;i++)
        {
            dist[i]=LLONG_MAX;
        }
        dist[l] = 0;
        queue<ll> q; 
        q.push(l);
        while (!q.empty())
        {
            ll u1 = q.front(); 
            q.pop();
            for(int i=0;i<r;i++)
            {
                ll v=(u1+num[i])%10000;
                if(dist[v]==LLONG_MAX)
                {
                    dist[v]=dist[u1]+1;
                    q.push(v); 
                }
            }
        }
        if(dist[u]==LLONG_MAX) cout<<"Permanently Locked\n";
        else cout<<dist[u]<<"\n";
    }
}
