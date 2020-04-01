//Using dp. Time-0.020s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ll n,ans,sub;
    while(cin>>n)
    {
        ll ar[n][n];
        for (int i = 0; i < n; i++) 
        {   
            for (int j = 0; j < n; j++) 
            {
                cin>>ar[i][j];
                if (i > 0) ar[i][j] += ar[i - 1][j]; 
                if (j > 0) ar[i][j] += ar[i][j - 1]; 
                if (i > 0 && j > 0) ar[i][j] -= ar[i - 1][j - 1]; 
            }
        }
        ans=LLONG_MIN;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                for (int k = i; k < n; k++) 
                    for (int l = j; l < n; l++) 
                    {
                        sub= ar[k][l]; 
                        if (i > 0) sub -= ar[i - 1][l]; 
                        if (j > 0) sub -= ar[k][j - 1]; 
                        if (i > 0 && j > 0) sub+= ar[i - 1][j - 1]; 
                        ans= max(ans, sub); 
                    }
        cout<<ans<<"\n";
    }    
}
