//Simple traversal. Time-0.020s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

char directions[] = {'N', 'E', 'S', 'W'};
int xChange[] = {0, 1, 0, -1};
int yChange[] = {1, 0, -1, 0};

int main()
{
    ll n,m,s,sx,sy,orien,x,y,count;
    string st;
    while(cin>>n>>m>>s)
    {
        if(n==0 && m==0 && s==0) break;
        char ar[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>ar[i][j];
                if(ar[i][j]=='N' || ar[i][j]=='S' || ar[i][j]=='L' || ar[i][j]=='O')
                {
                    sx=i;
                    sy=j;
                }
            }
        }
        if (ar[sx][sy]=='N') orien=0;
        else if (ar[sx][sy]=='L') orien=1;
        else if (ar[sx][sy]=='S') orien=2;
        else if (ar[sx][sy]=='O') orien=3;
        cin>>st;
        count=0;
        for(int i=0;i<s;i++)
        {
            if (st[i]=='D') 
            {
                orien = (orien+1)%4;
            }
            else if (st[i]=='E') 
            {
                orien=(orien+3)%4;
            }
            else 
            {
                x=sx; y=sy;
                if (orien==0) x--;
                else if (orien==1) y++;
                else if (orien==2) x++;
                else y--;
                
                if (y<0 || y>=m || x<0 || x>=n || ar[x][y]=='#') continue;
                else {
                    ar[sx][sy]='.';
                    if (ar[x][y]=='*') count++;
                    sx=x; sy=y;
                }
            }
        }
        cout<<count<<"\n";
    }
}
