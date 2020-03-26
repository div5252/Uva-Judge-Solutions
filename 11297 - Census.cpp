//Used 1D segment tree. Time-1.380s. Though it can be done with 2D segment tree, leading to a faster solution.

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>

class SegmentTree { // the segment tree is stored like a heap array
private:
    ll mx[2004],mn[2004],A[2004]; 
    ll n;
    ll left (ll p) { return p << 1; } // same as binary heap operations
    ll right(ll p) { return (p << 1) + 1; }
public:
    void read(ll n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
        }
    }
    void build(ll p, ll L, ll R) { // O(n)
        if (L == R) // as L == R, either one is fine
        {
            mx[p]=A[L];
            mn[p]=A[L];
        }    
        else { // recursively compute the values
            build(left(p) , L , (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R );
            mn[p]=min(mn[left(p)],mn[right(p)]);
            mx[p]=max(mx[left(p)],mx[right(p)]);
        }
    }

    ll rmxq(ll p, ll L, ll R, ll i, ll j) { // O(log n)
        if (i > j) return LLONG_MIN;
        if(i==L && j==R) return mx[p];
        ll m=(L+R)/2;
        ll p1 = rmxq(left(p) , L , (L+R) / 2, i, min(j,m));
        ll p2 = rmxq(right(p), (L+R) / 2 + 1, R , max(i,m+1), j);
        return max(p1,p2); // as in build routine
    }
    ll rmnq(ll p, ll L, ll R, ll i, ll j) { // O(log n)
        if (i > j) return LLONG_MAX;
        if(i==L && j==R) return mn[p];
        ll m=(L+R)/2;
        ll p1 = rmnq(left(p) , L , (L+R) / 2, i, min(j,m));
        ll p2 = rmnq(right(p), (L+R) / 2 + 1, R , max(i,m+1), j);
        return min(p1,p2); // as in build routine
    }
    void update(ll p, ll L, ll R, ll pos, ll val){
        if (L == R)
        {
            mn[p] = val;
            mx[p] = val;
        }    
        else{
            ll m=(L+R)/2;
            if(pos<=m) update(left(p),L,m,pos,val);
            else update(right(p),m+1,R,pos,val);
            mn[p]=min(mn[left(p)],mn[right(p)]);
            mx[p]=max(mx[left(p)],mx[right(p)]);
        }
    }
};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,a,q,x,y,v,x1,x2,y1,y2,M,m;
    char ch;
    cin>>n;
    SegmentTree st[n];
    for(int i=0;i<n;i++)
    {
        st[i].read(n);
        st[i].build(1,0,n-1);
    }
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>ch;
        if(ch=='c')
        {
            cin>>x>>y>>v;
            st[x-1].update(1,0,n-1,y-1,v);
        }
        else
        {
            cin>>x1>>y1>>x2>>y2;
            M=st[x1-1].rmxq(1,0,n-1,y1-1,y2-1);
            m=st[x1-1].rmnq(1,0,n-1,y1-1,y2-1);
            for(int i=x1;i<x2;i++)
            {
                M=max(M,st[i].rmxq(1,0,n-1,y1-1,y2-1));
                m=min(m,st[i].rmnq(1,0,n-1,y1-1,y2-1));
            }
            cout<<M<<" "<<m<<"\n";
        }
    }
}
