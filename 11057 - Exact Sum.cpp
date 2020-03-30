//Using binary search. Time-0.020s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ll n,m,i,j,i1,i2;
    while(cin>>n)
    {
        ll ar[n];
        cout<<"Peter should buy books whose prices are ";
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        cin>>m;
        sort(ar,ar+n);
        i=0; j=n-1;
        while(i < j)
        {
            if(ar[i]+ar[j]<m)
            {
                i++;
            }    
            else if(ar[i]+ar[j]==m)
            {
                i1=i;
                i2=j;
                i++;
                j--;
            }
            else j--;
        }
        cout<<ar[i1]<<" and "<<ar[i2]<<".\n\n";
    }
}
