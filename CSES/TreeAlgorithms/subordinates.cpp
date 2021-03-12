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
 
vector<vector<int>> adj;
vector<int> ans;
vector<int> vis;
 
void dfs(int u)
{
    vis[u]=1;
    for(int v : adj[u])
    {
        if(!vis[v])
        {
            dfs(v);
            ans[u] += ans[v]+1;
        }
    }
}
 
signed main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    auto startTime = curTime();
 
    int n;
    cin>>n;

    adj.resize(n);
    vis.resize(n);
    ans.resize(n);

    for(int i=0;i<n-1;i++)
    {
        int x;
        cin>>x;
        x--;

        adj[i+1].push_back(x);
        adj[x].push_back(i+1);
    }

    dfs(0);

    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
 
    auto stopTime = curTime();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
