//Accepted. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    vll p={1,2,3,4,5,6,7,8};
    ll flag,t,ar[8],ans,s;
    vector<vector<ll> > v;
    do{    
        flag=0;
        for(int i=0;i<8;i++)
        {
            for(int j=i+1;j<8;j++)
            {
                if(abs(j-i)==abs(p[j]-p[i]))
                {
                    flag=1; break;
                }
            }
        }
        if(flag==0)
        {
            v.push_back(p); 
        }
    }while(next_permutation(p.begin(),p.end())); 
    t=0;
    while(cin>>ar[0])
    {
        t++;
        cout<<"Case "<<t<<": ";
        for(int i=1;i<8;i++)
        {
            cin>>ar[i];
        }
        ans=7;
        for(ll i=0;i<v.size();i++)
        {
            s=0;
            for(ll j=0;j<8;j++)
            {
                if(ar[j]!=v[i][j]) s++;
            }
            ans=min(ans,s);
        }
        cout<<ans<<"\n";
    }
}

