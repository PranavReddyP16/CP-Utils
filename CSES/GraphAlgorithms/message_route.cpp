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
vector<int> par;
vector<int> vis;

signed main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    auto startTime = curTime();

    int n,m;
    cin>>n>>m;

    adj.resize(n);
    par.resize(n);
    vis.resize(n);

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--;v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    vis[0]=1;
    q.push(0);

    while(!q.empty())
    {
        int u = q.front();
        vis[u]=1;
        q.pop();

        for(int v : adj[u])
        {
            if(!vis[v])
            {
                vis[v]=1;
                q.push(v);
                par[v] = u;
            }
        }
    }

    if(vis[n-1]==0)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    vector<int> ans;
    int temp = n-1;
    while(temp!=0)
    {
        ans.push_back(temp+1);
        temp = par[temp];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());

    cout<<sz(ans)<<endl;
    for(int i=0;i<sz(ans);i++) cout<<ans[i]<<" ";
    cout<<endl;

    auto stopTime = curTime();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
