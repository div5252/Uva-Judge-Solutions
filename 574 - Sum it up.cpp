//Using backtracking. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

ll n,t;
ll ar[13];
vll ans;
map<vll,bool> check;
void backtrack(ll m, ll sum, vll ans)
{
    if(sum==t)
    {
        if(check[ans]) return;
        check[ans]=true;
        cout<<ans[0];
        for(int i=1;i<ans.size();i++)
        {
            cout<<"+"<<ans[i];
        }
        cout<<"\n";
    }
    if(sum>t || m==n) return;
    for(int i=m;i<n;i++)
    {
        ans.push_back(ar[i]);
        backtrack(i+1,sum+ar[i],ans);
        ans.pop_back();
    }
}
int main()
{
    while(cin>>t>>n)
    {
        if(n==0) break;
        cout<<"Sums of "<<t<<":\n";
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        check.clear();
        backtrack(0,0,ans);
        if(check.size()==0) cout<<"NONE\n";
    }    
}
