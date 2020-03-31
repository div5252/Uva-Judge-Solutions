//Using greedy. Time-0.010s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ll n,m,cost,flag;
    while(cin>>n>>m)
    {
        if(n==0 && m==0) break;
        ll d[n],k[m];
        for(int i=0;i<n;i++)
        {
            cin>>d[i];
        }
        for(int i=0;i<m;i++)
        {
            cin>>k[i];
        }
        flag=0; cost=0;
        if(m<n) cout<<"Loowater is doomed!\n";
        else
        {
            sort(d,d+n);
            sort(k,k+m);
            ll j=0;
            for(int i=0;i<n;i++)
            {
                while(k[j]<d[i] && j<m)
                {
                    j++;
                }
                if(j==m)
                {
                    cout<<"Loowater is doomed!\n";
                    flag=1;
                    break;
                }
                cost+=k[j];
                j++;
            }
            if(flag==0)
            {
                cout<<cost<<"\n";
            }
        }
    }
}
