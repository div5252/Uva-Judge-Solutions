//Using MST. Time-0.410s

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

int main()
{
    ll m,n,sum,a,b,c;
    while(cin>>m>>n)
    {
        if(m==0 && n==0) break;
        vector<pair<ll, pair<ll,ll> > > EdgeList;
        sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b>>c;
            EdgeList.push_back(make_pair(c,make_pair(a,b)));
            sum+=c;
        }
        sort(EdgeList.begin(), EdgeList.end()); // sort by edge weight O(E log E)
        ll mst_cost = 0;
        UnionFind UF(m); // all V are disjoint sets initially
        for (int i = 0; i < n; i++) { // for each edge, O(E)
            pair<ll, pair<ll,ll> > front = EdgeList[i];
            if (!UF.isSameSet(front.second.first, front.second.second)) { // check
                mst_cost += front.first; // add the weight of e to MST
                UF.unionSet(front.second.first, front.second.second); // link them
        } } 
        cout<<sum-mst_cost<<"\n";
    }
}
