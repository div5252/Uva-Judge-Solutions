//Using dp. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

const int MOD=1000000;
int main() 
{
    ll n,k,m;
    while(cin>>n>>k>>m)
    {
        ll dp[52][52]={};
        dp[0][0]=1;
        for(int i = 1; i <= k; i++) 
        {
            for(int j = 1; j <= n; j++) 
            {
                for(int k = 1; k <= m; k++) 
                {
                    if(j-k>=0)
                    {
                        dp[i][j] += dp[i-1][j-k];
                    }    
                }
            }
        }
        cout<<dp[k][n]<<"\n";
    }
}
