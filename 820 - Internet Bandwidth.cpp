//Using Edmonds Karp. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

ll res[105][105], mf, f, s, t; // global variables
vll p; // p stores the BFS spanning tree from s
void augment(ll v, ll minEdge) { // traverse BFS spanning tree from s->t
    if (v == s) { f = minEdge; return; } // record minEdge in a global var f
    else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v]));
                           res[p[v]][v] -= f; res[v][p[v]] += f; } }
                           
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,c,T=0,u,v,bw;
    while(cin>>n)
    {
        if(n==0) break;
        T++;
        cout<<"Network "<<T<<"\nThe bandwidth is ";
        cin>>s>>t>>c;
        s--; t--;
        for(int i=0;i<105;i++)
        {
            for(int j=0;j<105;j++)
            {
                res[i][j]=0;
            }
        }
        for(int i=0;i<c;i++)
        {
            cin>>u>>v>>bw;
            u--; v--;
            res[u][v]+=bw;
            res[v][u]+=bw;
        }
        mf = 0; 
        while (1) { 
            f = 0;
            vll dist(105, INT_MAX); dist[s] = 0; queue<int> q; q.push(s);
            p.assign(105, -1); 
            while (!q.empty()) {
                ll u = q.front(); q.pop();
                if (u == t) break; 
                for (int v = 0; v < 105; v++) // note: this part is slow
                    if (res[u][v] > 0 && dist[v] == INT_MAX)
                        dist[v] = dist[u] + 1, q.push(v), p[v] = u; // 3 lines in 1!
            }
            augment(t, INT_MAX); // find the min edge weight ‘f’ in this path, if any
            if (f == 0) break; // we cannot send any more flow (‘f’ = 0), terminate
            mf += f; // we can still send a flow, increase the max flow!
        }
        cout<<mf<<".\n\n";
    }
}    
