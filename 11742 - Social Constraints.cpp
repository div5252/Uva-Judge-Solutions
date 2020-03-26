//Using complete search. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ll n,m,ans,flag;
    while(cin>>n>>m)
    {
        if(n==0 && m==0) break;
        ll ar[m],br[m],cr[m],p[n];
        for(int i=0;i<n;i++)
        {
            p[i]=i;
        }
        for(int i=0;i<m;i++)
        {
            cin>>ar[i]>>br[i]>>cr[i];
        }
        ans=0;
        do{
            flag=0;
            for(int i=0;i<m;i++)
            {
                if(cr[i]>0 && abs(p[ar[i]]-p[br[i]])>cr[i] )
                {
                    flag=1; break;
                }
                if(cr[i]<0 && abs(p[ar[i]]-p[br[i]])<(-cr[i]) )
                {
                    flag=1; break;
                }
            }
            if(flag==0) ans++;
        }while(next_permutation(p,p+n));
        cout<<ans<<"\n";
    }
}

