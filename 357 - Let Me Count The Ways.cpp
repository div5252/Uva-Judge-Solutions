//Using dp. Time-0.000s
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main() 
{
    ll c[]={1,5,10,25,50},n;
    ll dp[30052]={};
    dp[0]=1;
    for (int i=0;i<5;i++)
    {
        for (int j=c[i];j<30052;j++)
        {
            dp[j]+=dp[j-c[i]];
        }
    }
    while(cin>>n)
    {    
        if(dp[n]==1) cout<<"There is only 1 way to produce "<<n<<" cents change.\n";
        else cout<<"There are "<<dp[n]<<" ways to produce "<<n<<" cents change.\n";
    }
}
