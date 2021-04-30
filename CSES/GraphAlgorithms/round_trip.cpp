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

int dfs(int u)
{
    vis[u]=1;

    for(int v : adj[u])
    {
        if(!vis[v])
        {
            par[v] = u;
            int temp = dfs(v);

            if(temp!=-1) return temp;
        }

        else if(par[u]!=v)
        {
            par[v] = u;
            return u;
        }
    }

    return -1;
}

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

    int ans=-1;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            int temp = dfs(i);
            if(temp!=-1)
            {
                ans = temp;
                break;
            }
        }
    }

    if(ans==-1) cout<<"IMPOSSIBLE"<<endl;
    else
    {
        vector<int> res;

        res.push_back(ans);
        int start=ans;
        ans = par[ans];

        while(ans!=start)
        {
            res.push_back(ans);
            ans = par[ans];
        }
        res.push_back(start);

        cout<<sz(res)<<endl;
        for(int i=0;i<sz(res);i++) cout<<res[i]+1<<" ";
        cout<<endl;
    }

    auto stopTime = curTime();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
