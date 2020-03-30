//Using binary search. Time-0.000s.

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

bool fill(ll ar[],ll m,ll c,ll n)
{
    ll cnt=1;
    ll current=c;
    for(int i=0;i<n;i++)
    {
        if(ar[i]>c) return false;
        if(ar[i]>current)
        {
            if(cnt==m) return false;
            cnt++;
            current=c;
        }
        current-=ar[i];
    }
    return true;
}
int main()
{
    ll n,m,l,r,ans,mid;
    while(cin>>n>>m)
    {
        ll ar[n];
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        l=1;
        r=1000000000;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(fill(ar,m,mid,n))
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        cout<<ans<<"\n";
    }
}
