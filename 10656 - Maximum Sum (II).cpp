//Accepted. Time-0.010s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ll n,k,a;
    while(cin>>n)
    {
        if(n==0) break;
        vll v;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            if(a) v.push_back(a);
        }
        int k=v.size();
        if(!k) cout<<"0\n";
        else
        {
            for(int i=0;i<k;i++)
            {
                if(i) cout<<" ";
                cout<<v[i];
            }
            cout<<"\n";
        }
    }
}
