//Using KMP. Time-0.0303s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>
#define ld long double

char T[2000005], P[2000005]; // T = text, P = pattern
int b[2000005], n, m, ans; // b = back table, n = length of T, m = length of P

void kmpPreprocess() { // call this before calling kmpSearch()
    int i = 0, j = -1; b[0] = -1; // starting values
    while (i < m) { // pre-process the pattern string P
        while (j >= 0 && P[i] != P[j]) j = b[j]; // different, reset j using b
        i++; j++; // if same, advance both pointers
        b[i] = j; // observe i = 8, 9, 10, 11, 12, 13 with j = 0, 1, 2, 3, 4, 5
} } // in the example of P = "SEVENTY SEVEN" above

void kmpSearch() { // this is similar as kmpPreprocess(), but on string T
    int i = 0, j = 0; // starting values
    while (i < n) { // search through string T
        while (j >= 0 && T[i] != P[j]) j = b[j]; // different, reset j using b
        i++; j++; // if same, advance both pointers
        if (j == m) { // a match found when j == m
            //printf("P is found at index %d in T\n", i - j);
            ans++;
            j = b[j]; // prepare j for the next possible match
} } }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    while(cin>>s)
    {
        if(s==".") break;
        for(int i=0;i<s.size();i++)
        {
            P[i]=s[i];
            T[i]=s[i];
        }
        for(int i=0;i<s.size();i++)
        {
            T[i+s.size()]=s[i];
        }
        n=2*s.size();
        m=s.size();
        ans=0;
        kmpPreprocess();
        kmpSearch();
        cout<<ans-1<<"\n";
    }
}
