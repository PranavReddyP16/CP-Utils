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
vector<int> col;

bool dfs(int u)
{
    bool ans = true;
    for(int v : adj[u])
    {
        if(col[v]==-1)
        {
            col[v] = (col[u]+1)%2;
            ans = ans&dfs(v);
        }

        else if(col[v]==col[u])
        {
            return false;
        }
    }

    return ans;
}

signed main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    auto startTime = curTime();

    int n,m;
    cin>>n>>m;

    adj.resize(n);
    col.resize(n,-1);

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--;v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ans = true;
    for(int i=0;i<n;i++)
    {
        if(col[i]==-1)
        {
            col[i]=0;
            ans = ans&dfs(i);
        }
    }

    if(ans==false)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        for(int i=0;i<n;i++) cout<<col[i]+1<<" ";
        cout<<endl;
    }

    auto stopTime = curTime();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
