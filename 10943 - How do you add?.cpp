//Using dp. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

const int MOD=1000000;
int main() 
{
    ll n,k,dp[205][205];
    dp[0][0]=1;
    for(int i=1;i<=200;i++) 
    {
		dp[i][0] = 1;
		for(k=1;k<=i;k++)
		{
			dp[i][k]=(dp[i-1][k-1]+dp[i-1][k])%MOD;
		}	
	}
    while(cin>>n>>k)
    {
        if(n==0 && k==0) break;
        cout<<dp[n+k-1][k-1]<<"\n";
    }
}
