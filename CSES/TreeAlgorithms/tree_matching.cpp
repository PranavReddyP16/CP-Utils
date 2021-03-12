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
vector<vector<int>> dp;

void dfs(int u)
{
    vis[u]=1;
    int mn=inf;
    int sum=0;
    for(int v : adj[u])
    {
        if(!vis[v])
        {
            dfs(v);
            if(max(dp[v][0],dp[v][1]) > dp[v][0]) mn = min(mn, dp[v][1]-dp[v][0]);
            else mn = min(mn, (int)0);
            sum += max(dp[v][0],dp[v][1]);
        }
    }

    if(sz(adj[u])==1 && u!=0)
    {
        dp[u][0]=0;
        dp[u][1]=0;
    }
    else
    {
        dp[u][0] = sum;
        if(mn<inf) dp[u][1] = sum-mn+1;
        else dp[u][1] = sum+1;
    }
}

signed main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    auto startTime = curTime();

    int n;
    cin>>n;

    dp.resize(n,vector<int> (2));
    adj.resize(n);
    vis.resize(n);

    adj.resize(n);
    for(int i=0;i<n-1;i++) {
        int u,v;
        cin>>u>>v;
        u--;v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }

    dfs(0);
    //for(int i=0;i<n;i++)
    //{
    //    cout<<"dp for node "<<i+1<<" is: "<<dp[i][0]<<" "<<dp[i][1]<<endl;
    //}

    cout<<max(dp[0][0],dp[0][1])<<endl;

    auto stopTime = curTime();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
