//Using MST. Time-0.000s

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

vector<pair<ll,long double > > AdjList[202];
vll visited;
void dfs(ll u, ll v_end, long double max_val)
{
    if (u == v_end)
        cout<<fixed<<setprecision(3)<< max_val<<"\n";
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
    ll n,t=0,a,b;
    while(cin>>n)
    {
        if(n==0) break;
        t++;
        cout<<"Scenario #"<<t<<"\n";
        for(int i=0;i<n;i++)
        {
            AdjList[i].clear();
        }
        visited.clear();
        visited.assign(n,0);
        vector<pair<long double,pair<ll,ll> > > EdgeList;
        vector<pair<ll,ll> > c;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            c.push_back(make_pair(a,b));
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                long double dist=sqrt(pow(c[i].first-c[j].first,2)+pow(c[i].second-c[j].second,2));
                EdgeList.push_back(make_pair(dist,make_pair(i,j)));
            }
        }
        sort(EdgeList.begin(), EdgeList.end());
        UnionFind UF(n); // all V are disjoint sets initially
        for (int i = 0; i < EdgeList.size(); i++) { // for each edge, O(E)
            pair<double, pair<ll,ll> > front = EdgeList[i];
            if (!UF.isSameSet(front.second.first, front.second.second)) { // check
                AdjList[front.second.first].push_back(make_pair(front.second.second,front.first));
                AdjList[front.second.second].push_back(make_pair(front.second.first,front.first));
                UF.unionSet(front.second.first, front.second.second); // link them
        } }
        cout<<"Frog Distance = ";
        dfs(0,1,0);
        cout<<"\n";
    }
}
