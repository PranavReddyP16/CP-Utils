#pragma GCC optimize("Ofast")

#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
using namespace std::chrono;

#define ld long double
#define sz(c) ((long long)c.size())
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long
const int inf = 1e18;

const int mod = 1e9 + 7;
const int mod2 = 998244353;

vector<vector<int>> adj;
vector<int> height;
vector<int> vis;
vector<vector<int>> ancestor;

void dfs(int u)
{
    vis[u]=1;
    for(int v : adj[u])
    {
        if(!vis[v])
        {
            height[v] = height[u]+1;
            dfs(v);
            ancestor[v][0] = u;
        }
    }
}

int walk(int u, int dist)
{
    int ans=u;
    int cnt=0;
    while(dist)
    {
        if(dist%2) ans = ancestor[ans][cnt];
        cnt++;
        dist>>=1;
    }

    return ans;
}

signed main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    auto startTime = high_resolution_clock::now();

    int n,q;
    cin>>n>>q;

    adj.resize(n);
    height.resize(n);
    vis.resize(n);
    ancestor.resize(n, vector<int> (30));

    for(int i=0;i<n-1;i++)
    {
        int u;
        cin>>u;
        u--;

        adj[u].push_back(i+1);
        adj[i+1].push_back(u);
    }

    dfs(0);
    //for(int i=0;i<n;i++) cout<<height[i]<<" ";
    //cout<<endl;

    for(int i=1;i<30;i++)
    {
        for(int j=0;j<n;j++)
        {
            ancestor[j][i] = ancestor[ancestor[j][i-1]][i-1];
        }
    }

    while(q--)
    {
        int x,k;
        cin>>x>>k;
        x--;

        if(height[x] < k)
        {
            cout<<-1<<endl;
            continue;
        }

        cout<<walk(x, k)+1<<endl;
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
