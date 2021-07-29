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

vector<vector<int>> adj;
vector<pair<int, int>> arr;
vector<int> vis;
int N;
vector<int> t;

void update(int pos, int val)
{
    t[pos+N] = val;
    for(pos=(pos+N)>>1;pos>0;pos>>=1)
    {
        t[pos] = t[pos<<1] + t[pos<<1|1];
    }
}

int query(int l, int r)
{
    int ans=0;
    for(l+=N,r+=N;l<r;l>>=1,r>>=1)
    {
        if(l&1) ans += t[l++];
        if(r%2==0) ans += t[r--];
    }

    if(l==r) ans+=t[l];

    return ans;
}
void dfs(int u, int& tim) {
    vis[u]=1;

    arr[u].first = tim;
    for(int v : adj[u]) {
        if(!vis[v]) {
            tim++;
            dfs(v, tim);
        }
    }
    tim++;
    arr[u].second = tim;
}

signed main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    auto startTime = high_resolution_clock::now();

    int n,q;
    cin>>n>>q;
    N = 2*n;

    adj.resize(n);
    arr.resize(n);
    vis.resize(n);

    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    for(int i=0;i<n-1;i++) {
        int u,v;
        cin>>u>>v;
        u--;v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int tim=0;
    dfs(0, tim);

    t.resize(2*N);
    for(int i=0;i<n;i++) {
        t[arr[i].first+N] = a[i];
        t[arr[i].second+N] = a[i];
    }
    // for(int i=0;i<n;i++) cout<<arr[i].first<<" "<<arr[i].second<<endl;

    for(int i=N-1;i>0;i--) {
        t[i] = t[i<<1] + t[i<<1|1];
    }
    // for(int i=N;i<sz(t);i++) cout<<t[i]<<" ";
    // cout<<endl;

    while(q--) {
        int quer;
        cin>>quer;

        if(quer==1) {
            int s, x;
            cin>>s>>x;
            s--;

            update(arr[s].first, x);
            update(arr[s].second, x);
        }

        else {
            int s;
            cin>>s;
            s--;

            cout<<query(arr[s].first, arr[s].second)/2<<endl;
        }
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
