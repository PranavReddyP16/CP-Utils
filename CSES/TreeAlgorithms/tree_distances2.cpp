#pragma GCC optimize("Ofast")

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
vector<int> vis;
vector<int> dist;
vector<int> subtree;

void dfs(int u)
{
    vis[u]=1;
    for(int v : adj[u])
    {
        if(!vis[v])
        {
            dist[v] = dist[u]+1;
            dfs(v);
            subtree[u] += subtree[v];
        }
    }

    subtree[u]++;
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
    dist.resize(n);
    subtree.resize(n);

    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0);


    vector<int> ans(n);
    for(int i=0;i<n;i++) ans[0] += dist[i];

    vis.clear();
    vis.resize(n);

    queue<int> q;
    q.push(0);
    
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u]=1;

        for(int v : adj[u])
        {
            if(vis[v]) continue;
            q.push(v);
            vis[v]=1;

            ans[v] = ans[u] - subtree[v] + n - subtree[v];
        }
    }

    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;

    auto stopTime = curTime();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
