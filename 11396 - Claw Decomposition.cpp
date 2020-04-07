//Bipartite graph. Time-0.000s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

int main()
{
    ll n,l,a,b;
    while(cin>>n)
    {
        if(n==0) break;
        vll AdjList[n];
        ll color[n];
        while(cin>>a>>b)
        {
            if(a==0 && b==0) break;
            AdjList[a-1].push_back(b-1);
            AdjList[b-1].push_back(a-1);
        }
        queue<int> q; q.push(0);
        for(int i=0;i<n;i++)
        {
            color[i]=-1;
        }
        color[0] = 0;
        bool isBipartite = true; // addition of one boolean flag, initially true
        while (!q.empty() && isBipartite) { // similar to the original BFS routine
            int u = q.front(); q.pop();
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                if (color[AdjList[u][j]] == -1) { // but, instead of recording distance,
                    color[AdjList[u][j]] = 1 - color[u]; // we just record two colors {0, 1}
                    q.push(AdjList[u][j]); }
                else if (color[AdjList[u][j]] == color[u]) { // u & v.first has same color
                    isBipartite = false; break; } } } // we have a coloring conflict
        if(isBipartite) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
