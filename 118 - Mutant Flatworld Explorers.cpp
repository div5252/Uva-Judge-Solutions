//Accepted. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

char directions[] = {'N', 'E', 'S', 'W'};
int xChange[] = {0, 1, 0, -1};
int yChange[] = {1, 0, -1, 0};

int main()
{
    ll xs,ys,x,y,dir;
    char cf;
    string s;
    bool died;
    cin>>xs>>ys;
    ll scent[xs+1][ys+1]={};
    while(cin>>x>>y>>cf>>s)
    {
        for (int i=0;i<4;i++)
        {
            if (cf==directions[i]) dir= i;
        }        
        died = false;
        for (int i=0;i<s.size();i++)
        {
            if (s[i] == 'R')
            {
                dir = (dir + 1) % 4;
            }
            else if (s[i] == 'L')
            {
                dir = (dir + 3) % 4;
            }
            else
            {
                if ((x + xChange[dir]== -1) || (x + xChange[dir] == xs + 1) || (y + yChange[dir] == -1) || (y + yChange[dir] == ys + 1) )
                {
                    if (scent[x][y]==0)
                    {
                        scent[x][y] =1; 
                        died = true;
                        break;
                    }
                }
                else
                {
                    x+= xChange[dir];
                    y+= yChange[dir];
                }
            }
        }
        cout<<x<<" "<<y<<" "<<directions[dir]<<(died ? " LOST" :"") <<"\n";
    }
}
