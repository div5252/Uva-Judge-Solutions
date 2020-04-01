//Accepted. Time-0.080s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ll n,ans,sum;
    while(cin>>n)
    {
        if(n==0) break;
        ll ar[n];
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        ans=LLONG_MIN;
        sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=ar[i];
            ans=max(ans,sum);
            if(sum<0) sum=0;
        }
        if(ans<=0) cout<<"Losing streak.\n";
        else cout<<"The maximum winning streak is "<<ans<<".\n";
    }
}
