//Simple Traversal. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

char directions[] = {'N', 'E', 'S', 'W'};
int xChange[] = {-1, 0, 1, 0};
int yChange[] = {0, 1, 0, -1};

int main()
{
    ll r,c,sc,orien,ans,flag,lans,x,y;
    while(cin>>r>>c>>sc)
    {
        if(r==0 && c==0 && sc==0) break;
        char a[r][c];
        ll visit[r][c]={};
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin>>a[i][j];
            }
        }
        orien=3;
        ans=0;
        x=0; y=sc-1; flag=0;
        while(flag==0 && x>=0 && x<r && y>=0 && y<c)
        {
            if(visit[x][y]==0)
            {
                ans++;
                visit[x][y]=ans; 
                if(a[x][y]=='N') x--;
                else if(a[x][y]=='E') y++;
                else if(a[x][y]=='S') x++;
                else y--;
            }
            else
            {
                flag=1;
                ll temp=ans;
                ans=visit[x][y]-1;
                lans=temp-ans;
            }
        }
        if(!flag) cout<<ans<<" step(s) to exit\n";
        else cout<<ans<<" step(s) before a loop of "<<lans<<" step(s)\n";
    }
}
