//Accepted. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

string find(int x, int y, int a = 0, int b = 1, int c = 1, int d = 0) {
    int m = a + c, n = b + d;
    if (x == m && y == n)
        return "";
    if (x*n < y*m)
        return 'L' + find(x, y, a, b, m, n);
    else
        return 'R' + find(x, y, m, n, c, d);
}
int main()
{
    ll n,m;
    while(cin>>n>>m)
    {
        if(n==1 && m==1) break;
        cout<<find(n,m)<<"\n";
    }
}
