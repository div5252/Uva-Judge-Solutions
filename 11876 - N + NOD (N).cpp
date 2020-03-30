//Using binary search. Time-0.520s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

ll countDivisors(ll n) 
{ 
    ll cnt = 0; 
    for (int i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            if (n / i == i) 
                cnt++; 
            else  
                cnt = cnt + 2; 
        } 
    } 
    return cnt; 
}
int main()
{
    vll v;
    vll::iterator i1,i2;
    ll t,a,b;
    ll i=0; 
    v.push_back(1);
    while(v[i]<=1000000)
    {
        v.push_back(0);
        i++;
        v[i]+=(v[i-1]+countDivisors(v[i-1]));
    }
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>a>>b;
        cout<<"Case "<<i+1<<": ";
        i1=lower_bound(v.begin(),v.end(),a);
        i2=upper_bound(v.begin(),v.end(),b);
        cout<<i2-i1<<"\n";
    }
}
