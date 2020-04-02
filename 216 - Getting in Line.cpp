//Using dp. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main() 
{
    ll n,t;
    t=0;
    while(cin>>n)
    {
        if(n==0) break;
        t++;
        cout<<"**********************************************************\nNetwork #"<<t<<"\n";
        long double x[n],y[n];
        for(int i=0;i<n;i++)
        {
            cin>>x[i]>>y[i];
        }
        long double dp[n][(1<<n)],p[n][1<<n];
        for (int i=0; i<n; i++) 
        {
            fill(dp[i], dp[i]+(1<<n), (double)INT_MAX);
            fill(p[i], p[i]+(1<<n), 0);
        }
        for (int i=0; i<n; i++)
        {
            dp[i][(1<<n)-1]=0.0;
        }    
        for(int mask=(1<<n)-1;mask>=0;mask--)
        {
            for(int i=0;i<n;i++)
            {
                if(mask&(1<<i))
                {
                    for(int j=0;j<n;j++)
                    {
                        if(!(mask&(1<<j)))
                        {
                            if (dp[i][mask]>dp[j][mask|(1<<j)]+sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2))+(long double)16.0) 
                            {
                                dp[i][mask]=dp[j][mask|(1<<j)]+sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2))+(long double)16.0;
                                p[i][mask]=j;
                            }    
                        }
                    }
                }
            }
        }
        ll ans=0;
        for(int i=1; i<n; i++)
        {
            if (dp[i][1<<i]<dp[ans][1<<ans]) ans=i;
        }        
        ll mask=1<<ans;
        ll s=ans;
        while(mask!=(1<<n)-1)
        {
            ll j=p[s][mask];
            cout<<fixed<<setprecision(0)<<"Cable requirement to connect ("<<x[s]<<","<<y[s]<<") to ("<<x[j]<<","<<y[j]<<") is "<<setprecision(2)<<sqrt(pow(x[s]-x[j],2)+pow(y[s]-y[j],2))+(long double)16.0<<" feet.\n";
            mask|=(1<<j);
            s=j;
        }
        cout<<"Number of feet of cable required is "<<fixed<<setprecision(2)<<dp[ans][1<<ans]<<".\n";
    }
}
