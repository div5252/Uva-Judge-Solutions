#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ll t,n,ans;
    string s;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>s;
        cout<<"Case "<<i+1<<": ";
        ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='.')
            {
                s[i]='#'; s[i+1]='#'; s[i+2]='#';
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
}
