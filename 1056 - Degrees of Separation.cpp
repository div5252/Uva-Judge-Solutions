//Using Floyd Warshall. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll p,r,t=0;
    string a,b;
    while(cin>>p>>r)
    {
        if(p==0 && r==0) break;
        t++;
        //if(t!=1) cout<<"\n";
        cout<<"Network "<<t<<": ";
        map<string,ll> m;
        ll AdjMat[p][p];
        for(int i=0;i<p;i++)
        {
            for(int j=0;j<p;j++)
            {
                AdjMat[i][j]=INT_MAX;
                if(i==j) AdjMat[i][j]=0;
            }
        }
        ll k=0;
        for(int i=0;i<r;i++)
        {
            cin>>a>>b;
            if(m.find(a)==m.end())
            {
                m[a]=k;
                k++;
            }
            if(m.find(b)==m.end())
            {
                m[b]=k;
                k++;
            }
            AdjMat[m[a]][m[b]]=1;
            AdjMat[m[b]][m[a]]=1;
        }
        for (int k = 0; k < p; k++) // remember that loop order is k->i->j
            for (int i = 0; i < p; i++)
                for (int j = 0; j < p; j++)
                    AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
        ll ans=0,flag=0;
        for(int i=0;i<p;i++)
        {
            for(int j=0;j<p;j++)
            {
                if(i!=j)
                {
                    if(AdjMat[i][j]==INT_MAX)
                    {
                        flag=1;
                        break;
                    }
                    else ans=max(ans,AdjMat[i][j]);
                }
            }
        }
        if(flag==1) cout<<"DISCONNECTED";
        else cout<<ans;
        cout<<"\n\n";
    }
}    
