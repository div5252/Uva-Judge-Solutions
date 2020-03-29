//Accepted. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

ll t,n,m,p,q,prevx,prevy;
string s[10];
vector<string> ans;
bool move(char c)
{
    if(c=='I' || c=='E' || c=='H' || c=='O' || c=='V' || c=='A' || c=='#') return true;
    else return false;
}
void backtrack(ll x,ll y)
{
    if(x==n && y==q)
    {
        cout<<ans[0];
        for(int i=1;i<ans.size();i++)
        {
            cout<<" "<<ans[i];
        }
        cout<<"\n";
        return;
    }
    if((y!=0) && !(prevx==x && prevy==(y-1)) && move(s[x][y-1]))
    {
        ans.push_back("left");
        prevx=x;
        prevy=y;
        backtrack(x,y-1);
    }
    else if((y!=(m-1)) && !(prevx==x && prevy==(y+1)) && (move(s[x][y+1])))
    {
        ans.push_back("right"); 
        prevx=x;
        prevy=y;
        backtrack(x,y+1);
    }
    else if((x!=n) && (move(s[x+1][y])))
    {
        ans.push_back("forth"); 
        prevx=x;
        prevy=y;
        backtrack(x+1,y);
    }
}
int main()
{
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>s[n-i];
        }
        for(int i=0;i<m;i++)
        {
            if(s[1][i]=='@') {p=i; break;}
        }
        for(int i=0;i<m;i++)
        {
            if(s[n][i]=='#') {q=i; break;}
        }
        prevx=0; prevy=0;
        ans.clear();
        backtrack(1,p);
    }
}
