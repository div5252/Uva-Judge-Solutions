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
    ll t,s,p,x,y,put;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>s>>p;
        vector<pair<long double, pair<ll,ll> > > EdgeList;
        vector<pair<ll,ll> > c;
        for(int i=0;i<p;i++)
        {
            cin>>x>>y;
            c.push_back(make_pair(x,y));
        } 
        for(int i=0;i<p;i++)
        {
            for(int j=i+1;j<p;j++)
            {
                long double dist=sqrt(pow(c[i].first-c[j].first,2)+pow(c[i].second-c[j].second,2));
                EdgeList.push_back(make_pair(dist,make_pair(i,j)));
            }
        }
        long double ans=0;
        put=0;
        sort(EdgeList.begin(), EdgeList.end()); // sort by edge weight O(E log E)
        UnionFind UF(p); // all V are disjoint sets initially
        ll k=0;
        while (k < EdgeList.size() && put<(p-s)) { // for each edge, O(E)
            pair<long double, pair<ll,ll> > front = EdgeList[k];
            if (!UF.isSameSet(front.second.first, front.second.second)) { // check
                ans=max(ans,front.first); 
                put++;
                UF.unionSet(front.second.first, front.second.second); // link them
            } 
            k++;
        } 
        cout<<fixed<<setprecision(2)<<ans<<"\n";
    }
}
