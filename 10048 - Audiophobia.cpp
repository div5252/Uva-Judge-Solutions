//Using MST. Time-0.010s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

class UnionFind {                                              
private:
  vll p, rank, setSize;                       
  ll numSets;
public:
  UnionFind(ll N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (ll i = 0; i < N; i++) p[i] = i; }
  ll findSet(ll i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(ll i, ll j) { return findSet(i) == findSet(j); }
  void unionSet(ll i, ll j) { 
    if (!isSameSet(i, j)) { numSets--; 
    ll x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  ll numDisjointSets() { return numSets; }
  ll sizeOfSet(ll i) { return setSize[findSet(i)]; }
};
vector<pair<ll,ll> > AdjList[105];
vll visited;
ll max_w;

void dfs(ll u, ll v_end, ll max_val)
{
    if (u == v_end)
        max_w = max_val;
    visited[u] = 1;
    for (int i = 0; i < AdjList[u].size(); i++)
    {
        auto v = AdjList[u][i];
        if (!visited[v.first])
            dfs(v.first, v_end, max(max_val, v.second));
    }
}

int main()
{
    ll c,s,q,t=0,c1,c2,d;
    while(cin>>c>>s>>q)
    {
        if(c==0 && s==0 && q==0) break;
        for(int i=0;i<c;i++)
        {
            AdjList[i].clear();
        }
        if(t!=0) cout<<"\n";
        t++;
        cout<<"Case #"<<t<<"\n";
        vector<pair<ll, pair<ll,ll> > > EdgeList;
        for(int i=0;i<s;i++)
        {
            cin>>c1>>c2>>d;
            c1--; c2--;
            EdgeList.push_back(make_pair(d,make_pair(c1,c2)));
        } 
        sort(EdgeList.begin(), EdgeList.end()); // sort by edge weight O(E log E)
        UnionFind UF(c); // all V are disjoint sets initially
        for (int i = 0; i < s ; i++) { // for each edge, O(E)
            pair<ll, pair<ll,ll> > front = EdgeList[i];
            if (!UF.isSameSet(front.second.first, front.second.second)) { // check
                AdjList[front.second.first].push_back(make_pair(front.second.second,front.first));
                AdjList[front.second.second].push_back(make_pair(front.second.first,front.first));
                UF.unionSet(front.second.first, front.second.second); // link them
        } } 
        for(int i=0;i<q;i++)
        {
            cin>>c1>>c2;
            c1--; c2--;
            visited.clear();
            visited.resize(c,0);
            max_w=0;
            dfs(c1,c2,0);
            if(max_w==0)cout<<"no path\n";
            else cout<<max_w<<"\n";
        }
    }
}
