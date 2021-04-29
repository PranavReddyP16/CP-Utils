#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
using namespace std::chrono;

#define ll long long
#define ld long double
#define sz(c) ((ll)c.size())
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int ll
const ll inf = 1e18;

const int mod = 1e9 + 7;
const int mod2 = 998244353;

high_resolution_clock::time_point curTime() { return high_resolution_clock::now(); }

#define rep(i,n) for(int i=0;i<n;i++)

vector<int> parent;
vector<int> siz;

int root(int u)
{
    while(parent[u]!=u) u = parent[u];
    return u;
}

void merge(int u, int v)
{
    u = root(u);
    v = root(v);
    if(u==v) return;

    if(siz[u]<siz[v]) swap(u,v);

    parent[v] = u;
    siz[u] += siz[v];
}

signed main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    auto startTime = curTime();

    int n,m;
    cin>>n>>m;

    parent.resize(n);
    siz.resize(n,1);
    for(int i=0;i<n;i++) parent[i] = i;

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--;v--;

        merge(u,v);
    }

    set<int> nodes;
    for(int i=0;i<n;i++) nodes.insert(root(i));

    vector<int> ans;
    for(int x : nodes) ans.push_back(x+1);

    cout<<sz(ans)-1<<endl;
    for(int i=0;i<sz(ans)-1;i++)
    {
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }

    auto stopTime = curTime();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
