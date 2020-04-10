//Using MST. Time-0.050s

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
    ll n,m,c,ans,t;
    string b,e;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        if(i!=0) cout<<"\n";
        cin>>n>>m;
        vector<pair<ll, pair<ll,ll> > > EdgeList;
        map<string,ll> mp;
        ll k=0;
        for(int i=0;i<m;i++)
        {
            cin>>b>>e>>c;
            if(mp.find(b)==mp.end())
            {
                mp.insert(make_pair(b,k));
                k++;
            }
            if(mp.find(e)==mp.end())
            {
                mp.insert(make_pair(e,k));
                k++;
            }
            EdgeList.push_back(make_pair(c,make_pair(mp[b],mp[e])));
        } 
        sort(EdgeList.begin(), EdgeList.end()); // sort by edge weight O(E log E)
        ans=0;
        UnionFind UF(n); // all V are disjoint sets initially
        for (int i = 0; i < EdgeList.size() ; i++) { // for each edge, O(E)
            pair<ll, pair<ll,ll> > front = EdgeList[i];
            if (!UF.isSameSet(front.second.first, front.second.second)) { // check
                ans+=front.first;
                UF.unionSet(front.second.first, front.second.second); // link them
        } } 
        cout<<ans<<"\n";    
    }
}

