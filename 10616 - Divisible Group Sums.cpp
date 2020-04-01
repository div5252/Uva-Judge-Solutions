//Using DP. Time-0.010s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

ll mod(ll number, ll mod) {
    if (number >= 0)
        return number % mod;
    return (mod + (number % mod)) % mod;
}
int main()
{
    ll n,q,d,m,t=0;
    while(cin>>n>>q)
    {
        if(n==0 && q==0) break;
        t++;
        cout<<"SET "<<t<<":\n";
        ll ar[n];
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        for(int i=0;i<q;i++)
        {
            cin>>d>>m;
            cout<<"QUERY "<<i+1<<": ";
            ll dp[n+1][d][m+1];
            for(int j=0;j<=n;j++)
            {
                for(int k=0;k<d;k++)
                {
                    for(int l=0;l<=m;l++)
                    {
                        if(k==0 && l==0) dp[j][k][l]=1;
                        else if(j==0||l==0) dp[j][k][l]=0;
                        else
                            dp[j][k][l]=dp[j-1][mod(k+ar[j-1],d)][l-1]+dp[j-1][k][l];
                    }
                }
            }
            cout<<dp[n][0][m]<<"\n";
        }
    }
}
