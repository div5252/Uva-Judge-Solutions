//Using Greedy. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ll n,d,r,ans;
    while(cin>>n>>d>>r)
    {
        if(n==0 && d==0 && r==0) break;
        ll a[n],b[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        sort(a,a+n);
        sort(b,b+n);
        ans=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]+b[n-1-i]-d>0)
            {  
              ans+=(a[i]+b[n-1-i]-d)*r;
            }  
        }
        cout<<ans<<"\n";
    }
}
