//Accepted. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

string led[]={"YYYYNYY","YYYYYYY","YYYNNNN","YNYYYYY","YNYYNYY","NYYNNYY","YYYYNNY","YYNYYNY","NYYNNNN","YYYYYYN"};

int main()
{
    ll n,flag,k,l,i,j;
    while(cin>>n)
    {
        if(n==0) break;
        string s[n];
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
        }
        flag=0;
        for(int i=0;i<11-n;i++)
        {
            ll check[7]={};
            for(j=i,l=0;j<i+n;j++,l++)
            {
                for(k=0;k<7;k++)
                {
                    if(check[k]==1 && s[l][k]=='Y')
                    {
                        break;
                    }
                    if(led[j][k]=='N' && s[l][k]=='Y')
                    {
                        break;
                    }
                    else if(led[j][k]=='Y' && s[l][k]=='N')
                    {
                        check[k]=1;
                    }
                }
                if(k!=7) break;
            }
            if(l==n) {flag=1; break;}
        }
        if(flag==0) cout<<"MISMATCH\n";
        else cout<<"MATCH\n";
    }
}
