//Using binary search. Time-0.010s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

long double func(ll p,ll q,ll r,ll s,ll t,ll u,long double x)
{
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
int main()
{
    ll p,q,r,s,t,u;
    long double left,right,m;
    while(cin>>p>>q>>r>>s>>t>>u)
    {
        left=0;
        right=1;
        while((right-left)>0.0000001)
        {
            m=(left+right)/2;
            if(func(p,q,r,s,t,u,m)>0)
            {
                left=m;
            }
            else right=m;
        }
        if((func(p,q,r,s,t,u,0)*func(p,q,r,s,t,u,1))<=0)
            cout<<fixed<<setprecision(4)<<left<<"\n";
        else
            cout<<"No solution\n";
    }
}
