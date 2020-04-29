//Using Floyd Warshall. Time-0.010s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t,n,r,u,v,s,d;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cout<<"Case "<<i+1<<": ";
        cin>>n>>r;
        ll AdjMat[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                AdjMat[i][j]=INT_MAX;
                if(i==j) AdjMat[i][j]=0;
            }
        }
        for(int i=0;i<r;i++)
        {
            cin>>u>>v;
            AdjMat[u][v]=1;
            AdjMat[v][u]=1;
        }
        for (int k = 0; k < n; k++) // remember that loop order is k->i->j
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
        cin>>s>>d;
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            if(AdjMat[s][i]!=INT_MAX && AdjMat[i][d]!=INT_MAX)
            {
                ans=max(ans,AdjMat[s][i]+AdjMat[i][d]);
            }
        }
        cout<<ans<<"\n";
    }
}    
