//Accepted. Time-0.030s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ll t,d,l,h,q,p,c;
    string m;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        if(i!=0) cout<<"\n";
        cin>>d;
        vector<pair<string,pair<ll,ll> > > um;
        for(int i=0;i<d;i++)
        {
            cin>>m>>l>>h;
            um.push_back(make_pair(m,make_pair(l,h)));
        }
        cin>>q;
        string ans;
        for(int i=0;i<q;i++)
        {
            c=0;
            cin>>p;
            for(int i=0;i<d;i++)
            {
                if(((p-um[i].second.first)*(p-um[i].second.second))<=0)
                {
                    c++; ans=um[i].first;
                    if(c>1) break;
                }
            }
            if((c==0) || (c>1) )
            {
                cout<<"UNDETERMINED"<<"\n";
            }
            else cout<<ans<<"\n";
        }    
    }    
}

