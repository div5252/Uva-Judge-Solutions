//Using dp. Time-0.020s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main() 
{
    ll dp[30001],t,p,ans,n;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>p>>n;
        ll c[n];
        dp[0]=0;
        for (int i=1; i<=30000; i++)
        {
            dp[i]=LLONG_MAX;
        }
        for(int i=0;i<n;i++)
        {
            cin>>c[i];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=30000-c[i];j>=0;j--)
            {
                if(dp[j]!=LLONG_MAX)
                {
                    dp[j+c[i]]=min(dp[j+c[i]],dp[j]+1);
                }
            }
        }
        for(int i=p;i<=30000;i++)
        {
            if(dp[i]!=LLONG_MAX)
            {
                ans=i;
                break;
            }
        }
        cout<<ans<<" "<<dp[ans]<<"\n";
    }
}
