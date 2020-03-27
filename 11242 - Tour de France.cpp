//Accepted. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ll f,r;
    long double mx;
    while(cin>>f)
    {
        if(f==0) break;
        cin>>r;
        ll fa[f],ra[r];
        long double d[f*r];
        for(int i=0;i<f;i++)
        {
            cin>>fa[i];
        }
        for(int i=0;i<r;i++)
        {
            cin>>ra[i];
        }
        for(int i=0;i<f;i++)
        {
            for(int j=0;j<r;j++)
            {
                d[i*r+j]=((long double)ra[j]/(long double)fa[i]);
            }
        }
        sort(d,d+f*r);
        mx=0;
        for(int i=1;i<f*r;i++)
        {
            mx=max(mx,((long double)d[i]/(long double)d[i-1]));
        }
        cout<<fixed<<setprecision(2)<<mx<<"\n";
    }
}

