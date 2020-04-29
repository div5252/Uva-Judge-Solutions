//Using Floyd Warshall. time-0.090s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll a,b,n,t=0;
    while(cin>>a>>b)
    {
        if(a==0 && b==0) break;
        t++;
        cout<<"Case "<<t<<": average length between pages = ";
        ll AdjMat[105][105],pr[105]={};
        for(int i=0;i<105;i++)
        {
            for(int j=0;j<105;j++)
            {
                AdjMat[i][j]=INT_MAX;
            }
        }
        a--; b--;
        AdjMat[a][b]=1;
        pr[a]=1; pr[b]=1;
        while(cin>>a>>b)
        {
            if(a==0 && b==0) break;
            a--; b--;
            pr[a]=1; pr[b]=1;
            AdjMat[a][b]=1;
        }
        for (int k = 0; k < 105; k++) // remember that loop order is k->i->j
            for (int i = 0; i < 105; i++)
                for (int j = 0; j < 105; j++)
                    AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
        ll sum=0,den=0;
        for(int i=0;i<105;i++)
        {
            for(int j=0;j<105;j++)
            {
                if(i!=j && pr[i]==1 && pr[j]==1) 
                {
                    sum+=AdjMat[i][j];
                    den++;
                }    
            }
        }
        long double ans=(float)sum/(float)den;
        cout<<fixed<<setprecision(3)<<ans;
        cout<<" clicks"<<"\n";
    }   
}    
