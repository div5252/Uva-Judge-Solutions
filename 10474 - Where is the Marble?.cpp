//Accepted. Time-0.180s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ll n,q,t,a;
    t=0;
    while(cin>>n>>q)
    {
        if(n==0 && q==0) break;
        t++;
        cout<<"CASE# "<<t<<":\n";
        vll v;
        vll:: iterator it;
        for(ll i=0;i<n;i++)
        {
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<q;i++)
        {
            cin>>a;
            it=lower_bound(v.begin(),v.end(),a);
            if(it==v.end() || v[it-v.begin()]!=a)
            {
                cout<<a<<" not found\n";
            }
            else
            {
                cout<<a<<" found at "<<it-v.begin()+1<<"\n";
            }
        }
    }
}
