//Using Greedy. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ll t,n,sum,ans;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        ll ar[n];
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        sum=ar[0];
        ans=1;
        for(int i=1;i<n-1;i++)
        {
            if(sum+ar[i]<ar[i+1])
            {
                sum+=ar[i];
                ans++;
            }
        }
        cout<<ans+1<<"\n";
    }
}
