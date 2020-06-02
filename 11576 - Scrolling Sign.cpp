//Using KMP. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>
#define ld long double

char T[1005], P[1005]; // T = text, P = pattern
int b[1005], n, m; // b = back table, n = length of T, m = length of P

void kmpPreprocess() { // call this before calling kmpSearch()
    int i = 0, j = -1; b[0] = -1; // starting values
    while (i < m) { // pre-process the pattern string P
        while (j >= 0 && P[i] != P[j]) j = b[j]; // different, reset j using b
        i++; j++; // if same, advance both pointers
        b[i] = j; // observe i = 8, 9, 10, 11, 12, 13 with j = 0, 1, 2, 3, 4, 5
} } // in the example of P = "SEVENTY SEVEN" above

int kmpSearch() { // this is similar as kmpPreprocess(), but on string T
    int i = 0, j = 0; // starting values
    while (i < n) { // search through string T
        while (j >= 0 && T[i] != P[j]) j = b[j]; // different, reset j using b
        i++; j++; // if same, advance both pointers
        if (j == m) { // a match found when j == m
            //printf("P is found at index %d in T\n", i - j);
            //j = b[j]; // prepare j for the next possible match
        }
    } 
    return j;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t,k,w;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>k>>w;
        string s[w];
        for(int i=0;i<w;i++)
        {
            cin>>s[i];
        }
        ll ans=k;
        for(int i=0;i<w-1;i++)
        {
            for(int j=0;j<k;j++)
            {
                P[j]=s[i+1][j];
                T[j]=s[i][j];
            }
            n=k; m=k;
            kmpPreprocess();
            int tail=kmpSearch();
            ans+=k-tail;
        }
        cout<<ans<<"\n";
    }
}
