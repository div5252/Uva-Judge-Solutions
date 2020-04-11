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

int main()
{
    ll t,a,b,c,n,m,least,sleast;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>m;
        vector<pair<ll, pair<ll,ll> > > EdgeList;
        vll ans;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b>>c;
            a--; b--;
            EdgeList.push_back(make_pair(c,make_pair(a,b)));
        } 
        least=0;
        sort(EdgeList.begin(), EdgeList.end()); // sort by edge weight O(E log E)
        UnionFind UF(n); // all V are disjoint sets initially
        for (int i = 0; i < m ; i++) { // for each edge, O(E)
            pair<ll, pair<ll,ll> > front = EdgeList[i];
            if (!UF.isSameSet(front.second.first, front.second.second)) { // check
                least+=front.first;
                ans.push_back(i);   
                UF.unionSet(front.second.first, front.second.second); // link them
        } } 
        cout<<least<<" ";
        sleast=LLONG_MAX;
        for(int j=0;j<ans.size();j++)
        {
            ll sum=0,c=0;
            UnionFind UF2(n); // all V are disjoint sets initially
            for (int i = 0; i < m ; i++) { // for each edge, O(E)
                if(i==ans[j]) continue;
                pair<ll, pair<ll,ll> > front = EdgeList[i];
                if (!UF2.isSameSet(front.second.first, front.second.second)) { // check
                    sum+=front.first; c++;
                    UF2.unionSet(front.second.first, front.second.second); // link them
            } }
            if(c==(n-1)) sleast=min(sum,sleast); 
        }
        cout<<sleast<<"\n";
    }
}
