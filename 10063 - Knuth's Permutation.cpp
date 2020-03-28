//Accepted. Time-0.060s.

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

string s, ans, t;
string getString(char x) 
{ 
    string s(1, x); 
    return s;    
} 
void backtrack(ll m, string ans)
{
    if(m==s.size())
    {
        cout<<ans<<"\n";
        return;
    }
    for(int i=0;i<=m;i++)
    {
        t=ans;
        ans.insert(i,getString(s[m]));
        backtrack(m+1,ans);
        ans.erase(ans.begin()+i,ans.begin()+i+1);
    }
}
int main()
{
    ll t=0;
    while(cin>>s)
    {
        if(t!=0) cout<<"\n";
        ans=getString(s[0]);
        backtrack(1,ans);
        t++;
    }    
}
