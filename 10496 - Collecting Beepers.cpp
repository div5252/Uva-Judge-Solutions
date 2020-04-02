//Using dp. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main() 
{
    ll t,x[25],y[25],sx,sy,n;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>sx>>sy;
        cin>>x[0]>>y[0];
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i]>>y[i];
        }
        ll dp[n+1][(1<<(n+1))+1];
        for(int i=0;i<n+1;i++)
        {
            fill(dp[i],dp[i]+ (1<<(n+1))+1,LLONG_MAX);
        }
        for(int i=1;i<n+1;i++)
        {
            dp[i][(1<<(n+1))-1]=abs(x[i]-x[0])+abs(y[i]-y[0]);
        }
        for(int mask=(1<<(n+1))-1;mask>=0;mask--)
        {
            for(int i=0;i<n+1;i++)
            {
                for(int j=0;j<n+1;j++)
                {
                    if(j!=i && !(mask&(1<<j)))
                    {
                        dp[i][mask]=min(dp[i][mask],dp[j][mask|(1<<j)]+abs(x[j]-x[i])+abs(y[j]-y[i]));
                    }
                }
            }
        }
        cout<<"The shortest path has length "<<dp[0][1]<<"\n";
    }
}
