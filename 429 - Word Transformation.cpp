//Using BFS. Time-1.740s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};

int main()
{
    ll t;
    string s,a,b;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        if(i!=0) cout<<"\n";
        vector<string> dict;
        while(cin>>s)
        {
            if(s=="*") break;
            dict.push_back(s);
        }
        cin.ignore();
        while(getline(cin,s) && s!="")
        {
            stringstream ss(s);
            ss>>a>>b;
            queue<string> q;
            q.push(a);
            map<string,ll> dist;
            dist[a]=0;
            while(!q.empty())
            {
                string u=q.front();
                q.pop();
                for(int i=0;i<dict.size();i++)
                {
                    if(dist.count(dict[i])==0 && u.size()==dict[i].size())
                    {
                        ll df=0;
                        for(int j=0;j<u.size();j++)
                        {
                            if(u[j]!=dict[i][j]) df++;
                        }
                        if(df==1)
                        {
                            dist[dict[i]]=dist[u]+1;
                            q.push(dict[i]);
                        }
                    }
                }
            }
            cout<<a<<" "<<b<<" "<<dist[b]<<"\n";
        }
    }
}
