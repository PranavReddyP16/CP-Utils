#pragma GCC optimize("Ofast")

#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
using namespace std::chrono;

#define int long long
#define ld long double
#define sz(c) ((int)c.size())
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const int inf = 1e18;

const int mod = 1e9 + 7;
const int mod2 = 998244353;

vector<int> seg;

void build(int node, int start, int end, vector<int> &a) {
    if(start==end) seg[node] = a[start];
    else {
        int mid = (start+end)/2;
        build(node<<1, start, mid, a);
        build(node<<1|1, mid+1, end, a);

        seg[node] = seg[node<<1] + seg[node<<1|1];
    }
}

void update(int node, int pos, int val, int start, int end) {
    if(start==end) {
        seg[node] = val;
        return;
    }
    // cout<<node<<endl;

    int mid = (start+end)/2;
    if(pos<=mid) update(node<<1, pos, val, start, mid);
    else update(node<<1|1, pos, val, mid+1, end);

    seg[node] = seg[node<<1] + seg[node<<1|1];
}

int query(int node, int start, int end, int l, int r) {
    if(start>=l && end<=r) return seg[node];
    if(start>r || end<l) return 0;

    int mid = (start+end)/2;
    return query(node<<1, start, mid, l, r) + query(node<<1|1, mid+1, end, l, r);
}

signed main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    auto startTime = high_resolution_clock::now();

    int n,q;
    cin>>n>>q;

    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    while(__builtin_popcount(n)>1) {
        n++;
        a.push_back(0);
    }

    seg.resize(2*n);

    //build the segment tree recursively
    build(1, 0, n-1, a);

    while(q--) {
        int question;
        cin>>question;

        if(question==1) {
            int pos, val;
            cin>>pos>>val;

            update(1, pos-1, val, 0, n-1);
        }

        else {
            int l,r;
            cin>>l>>r;
            l--, r--;

            cout<<query(1, 0, n-1, l, r)<<endl;
        }
    }

    // for(int i=n;i<2*n;i++) {
    //     cout<<seg[i]<<" ";
    // }
    // cout<<endl;

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
