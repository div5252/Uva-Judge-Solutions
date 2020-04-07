//Using Kahn Algo. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ll n,t=0,m,tp;
    string s,s1;
    while(cin>>n)
    {
        t++;
        cout<<"Case #"<<t<<": Dilbert should drink beverages in this order:";
        map<string,ll> mp;
        string ans[n];
        vll g[n];
        ll ind[n]={};
        for(int i=0;i<n;i++)
        {
            cin>>s;
            mp[s]=i;
            ans[i]=s;
        }
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>s>>s1;
            g[mp[s]].push_back(mp[s1]);
            ind[mp[s1]]++;
        }
        priority_queue<ll> pq;
        for(int i=0;i<n;i++)
        {
            if(ind[i]==0) pq.push(-i);
        }
        while(!pq.empty())
        {
            tp=-pq.top();
            pq.pop();
            for(int i=0;i<g[tp].size();i++)
            {
                ind[g[tp][i]]--;
                if(ind[g[tp][i]]==0) pq.push(-g[tp][i]);
            }
            cout<<" "<<ans[tp];
        }
        cout<<".\n\n";
    }
}
