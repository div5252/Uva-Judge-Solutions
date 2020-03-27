//Using complete search. Time-0.010s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ll s,d,flag,ans,sum;
    while(cin>>s>>d)
    {
        ans=0;
        for(int i=0;i<(1<<12);i++)
        {
            ll ar[12];
            sum=0;
            for(int j=0;j<12;j++)
            {
                if((i&(1<<j))==0) ar[j]=s;
                else ar[j]=-d;
                sum+=ar[j];
            }
            flag=0;
            for(int j=0;j<8;j++)
            {
                if((ar[j]+ar[j+1]+ar[j+2]+ar[j+3]+ar[j+4])>=0)
                {
                    flag=1;
                }
            }
            if(flag==0)
            {
                ans=max(ans,sum);
            }
        }
        if(ans<=0) cout<<"Deficit"<<"\n";
        else cout<<ans<<"\n";
    }
}

