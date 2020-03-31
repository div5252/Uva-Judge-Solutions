//Using greedy. Time-0.020s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ll x,y,t,mn;
    t=0;
    while(cin>>x>>y)
    {
        if(x==0 && y==0) break;
        t++;
        cout<<"Case "<<t<<": ";
        ll b[x],s[y];
        mn=LLONG_MAX;
        for(int i=0;i<x;i++)
        {
            cin>>b[i];
            mn=min(mn,b[i]);
        }
        for(int i=0;i<y;i++)
        {
            cin>>s[i];
        }
        if(y>=x) cout<<"0\n";
        else
        {
            cout<<x-y<<" "<<mn<<"\n";
        }
    }
}
