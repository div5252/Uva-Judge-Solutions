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
    ll a,b,cnt;
    while(cin>>a)
    {   
        cin>>b;
        vector<pair<ll,ll> > EdgeList;
        EdgeList.push_back(make_pair(a,b));
        while(cin>>a)
        {
            if(a==-1) break;
            cin>>b;
            EdgeList.push_back(make_pair(a,b));
        }
        cnt=0;
        UnionFind UF(100001); // all V are disjoint sets initially
        for (int i = 0; i < EdgeList.size(); i++) { // for each edge, O(E)
            pair<ll,ll> front = EdgeList[i];
            if (!UF.isSameSet(front.first, front.second)) { // check
                cnt++;
                UF.unionSet(front.first, front.second); // link them
        } }
        cout<<EdgeList.size()-cnt<<"\n";
    }
}
