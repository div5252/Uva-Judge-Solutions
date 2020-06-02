//Using dp. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>
#define ld long double

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=0;
    string a,b;
    while(getline(cin,a))
    {
        if(a=="#") break;
        getline(cin,b);
        t++;
        cout<<"Case #"<<t<<": you can visit at most ";
        ll n=a.size(),m=b.size();
        ll dp[n+1][m+1];
        dp[0][0]=0;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0) dp[i][j]=0;
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    if(a[i-1]==b[j-1]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                }
            }
        }
        cout<<dp[n][m]<<" cities.\n";
    }
}
