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

int n,m;
vector<string> a;

vector<pair<int, int>> adj(pair<int, int> x) {
    vector<pair<int, int>> ans;

    if(x.first>0) ans.push_back({x.first-1, x.second});
    if(x.first<n-1) ans.push_back({x.first+1, x.second});
    if(x.second>0) ans.push_back({x.first, x.second-1});
    if(x.second<m-1) ans.push_back({x.first, x.second+1});

    return ans;
}

vector<pair<int, int>> ans;
vector<vector<int>> vis;

bool dfs(pair<int, int> u) {
    vis[u.first][u.second]=1;

    if(a[u.first][u.second]=='B') {
        ans.push_back(u);
        return true;
    }

    bool ok = false;
    for(pair<int, int> v : adj(u)) {
        if(a[v.first][v.second]!='#' && !vis[v.first][v.second]) {
            ok = ok or dfs(v);
        }
    }

    if(ok) ans.push_back(u);
    return ok;
}

signed main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    auto startTime = high_resolution_clock::now();

    cin>>n>>m;

    vis.resize(n, vector<int> (m));
    a.resize(n);

    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    pair<int, int> pos;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(a[i][j]=='A') pos = {i,j};
        }
    }

    bool ok = dfs(pos);
    if(!ok) {
        cout<<"NO"<<endl;
        return 0;
    }

    reverse(ans.begin(), ans.end());

    string res = "";
    for(int i=0;i<sz(ans)-1;i++) {
        if(ans[i+1].first>ans[i].first) res.push_back('D');
        else if(ans[i+1].first<ans[i].first) res.push_back('U');
        else if(ans[i+1].second>ans[i].second) res.push_back('R');
        else res.push_back('L');
    }

    cout<<"YES"<<endl;
    cout<<sz(res)<<endl;
    cout<<res<<endl;

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
