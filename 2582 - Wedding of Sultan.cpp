#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ll t;
    string s;
    cin>>t;
    for(int I=0;I<t;I++)
    {
        cout<<"Case "<<I+1<<"\n";
        stack<char> st;
        cin>>s;
        ll ans[27]={};
        st.push(s[0]);
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==st.top())
            {
                st.pop();
            }
            else
            {
                ans[st.top()-'A']++;
                st.push(s[i]);
                ans[s[i]-'A']++;
            }
        }
        for(int i=0;i<26;i++)
        {
            if(ans[i]>0) cout<<(char)(i+'A') <<" = "<<ans[i]<<"\n";
        }
    }
}
