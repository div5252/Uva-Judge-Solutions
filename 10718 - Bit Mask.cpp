//Using greedy. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    unsigned ll n,l,r,ans,t;
    while(cin>>n>>l>>r)
    {
        ans=0;
        for(int i=32;i>=0;i--)
        {
            t=ans|(1ll<<i);
            if( (t<=l) || ((t<=r) && !(n&(1ll<<i))) )
            {
                ans=t;
            }
        }
        cout<<ans<<"\n";
    }
}

