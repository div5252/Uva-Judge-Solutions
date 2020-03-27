// Using backtracking. Time-0.150s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

ll n,t,ans[20]={1};
ll prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41};
bool isPrime(ll a)
{
    for (int n : prime)
    {
        if (n == a) return true;
    }    
    return false;
}
void backtrack(ll l,bool visit[])
{
    if(l==n)
    {
        if (!isPrime(ans[n-1] + 1))
            return;
        for (int i = 0; i < n-1; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<ans[n-1];
        cout<<"\n";
        return;
    }
    for (int i = 2; i <= n; i++) 
    {
        if (visit[i]) continue;
        if (isPrime(i + ans[l - 1])) 
        {
            visit[i] = 1;
            ans[l] = i;
            backtrack(l + 1, visit);
            visit[i] = 0;
        }
    }
}
int main()
{
    while(cin>>n)
    {
        t++;
        if(t!=1) cout<<"\n";
        cout<<"Case "<<t<<":\n";
        bool visit[20]={0};
        backtrack(1,visit);
    }    
}

