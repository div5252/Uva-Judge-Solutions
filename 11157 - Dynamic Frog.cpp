//Using greedy. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ll t,n,d,ans,a;
    char c1,c2;
    vll big;
    vector<vll> small;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cout<<"Case "<<i+1<<": ";
        cin>>n>>d;
        big.clear();
        small.clear();
        big.push_back(0);
        small.push_back(vll());
        ll k=0;
        for(int i=0;i<n;i++)
        {
            cin>>c1>>c2>>a;
            if(c1=='B')
            {
                big.push_back(a);
                small.push_back(vll());
                k++;
            }
            else if(c1=='S')
            {
                small[k].push_back(a);
            }
        }
        big.push_back(d);
        ans=-1;
        for(int i=0;i<=k;i++)
        {
            ll ss=small[i].size();
            ll temp=-1;
            for(int j=2;j<ss;j++)
            {
                temp=max(temp,small[i][j]-small[i][j-2]);
            }
            if(ss<=1)
            {
                temp=max(big[i+1]-big[i],temp);
            }    
            else if(ss>1)
            {
                temp=max(small[i][1]-big[i],temp);
                temp=max(big[i+1]-small[i][ss-2],temp);
            }
            ans=max(ans,temp);
        }    
        cout<<ans<<"\n";  
    }
}
