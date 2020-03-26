//Accepted. Time-0.220s

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

class SegmentTree { // the segment tree is stored like a heap array
private:
    vll st, A;
    ll n;
    ll left (ll p) { return p << 1; } // same as binary heap operations
    ll right(ll p) { return (p << 1) + 1; }

    void build(ll p, ll L, ll R) { // O(n)
        if (L == R) // as L == R, either one is fine
            st[p] = A[L]; // store the index
        else { // recursively compute the values
            build(left(p) , L , (L + R) / 2);
            build(right(p), ((L + R) / 2) + 1, R );
            ll p1 = st[left(p)], p2 = st[right(p)];
            st[p] = p1+p2;
        }
    }

    ll rsq(ll p, ll L, ll R, ll i, ll j) { // O(log n)
        if (i > j) return 0;
        if(i==L && j==R) return st[p];
        ll m=(L+R)/2;
        return rsq(left(p),L,m,i,min(j,m))+rsq(right(p),m+1,R,max(i,m+1),j);
    }
    void update(ll p, ll L, ll R, ll pos, ll val){
        if (L == R)
            st[p] = val;
        else{
            ll m=(L+R)/2;
            if(pos<=m) update(left(p),L,m,pos,val);
            else update(right(p),m+1,R,pos,val);
            ll p1 = st[left(p)], p2 = st[right(p)];
            st[p] = p1+p2;
        }
    }

public:
    SegmentTree(const vll &_A) {
        A = _A; n = (int)A.size(); // copy content for local usage
        st.assign(4 * n, 0); // create large enough vector of zeroes
        build(1, 0, n - 1); // recursive build
    }
    ll rsq(ll i, ll j) { return rsq(1, 0, n - 1, i, j); } // overloading
    void update(ll pos, ll val) {return update(1,0,n-1,pos,val); }
};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,t,a,b;
    string s;
    t=0;
    while(cin>>n)
    {
        if(n==0) break;
        t++;
        if(t!=1) cout<<"\n";
        cout<<"Case "<<t<<":\n";
        vll v;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            v.push_back(a);
        }
        SegmentTree st(v);
        while(cin>>s)
        {
            if(s.compare("END")==0) break;
            cin>>a>>b;
            if(s.compare("S")==0)
            {
                st.update(a-1,b);
            }
            else
            {
                cout<<st.rsq(a-1,b-1)<<"\n";
            }
        }
    }
}
