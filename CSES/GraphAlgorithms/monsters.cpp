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

vector<pair<int, int>> adj(pair<int, int> a, int n, int m)
{
    vector<pair<int, int>> ans;
    if(a.first>0) ans.push_back({a.first-1,a.second});
    if(a.first<n-1) ans.push_back({a.first+1,a.second});
    if(a.second>0) ans.push_back({a.first,a.second-1});
    if(a.second<m-1) ans.push_back({a.first,a.second+1});

    return ans;
}

signed main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    auto startTime = curTime();

    int n,m;
    cin>>n>>m;

    vector<string> a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    vector<vector<int>> dist_mon(n, vector<int> (m,inf));
    queue<pair<int, int>> q;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='M')
            {
                dist_mon[i][j]=0;
                q.push({i,j});
            }
        }
    }

    while(!q.empty())
    {
        pair<int, int> u = q.front();
        q.pop();

        for(pair<int, int> v : adj(u, n, m))
        {
            if(dist_mon[v.first][v.second]==inf && a[v.first][v.second]!='#')
            {
                q.push(v);
                dist_mon[v.first][v.second] = dist_mon[u.first][u.second]+1;
            }
        }
    }

    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>> (m, {inf,inf}));
    vector<vector<int>> dist(n, vector<int> (m,inf));

    int f=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='A')
            {
                if(i==0 || i==n-1 || j==0 || j==m-1) f=1;

                q.push({i,j});
                dist[i][j]=0;
                par[i][j] = {i,j};
            }
        }
    }

    while(!q.empty())
    {
        pair<int, int> u = q.front();
        q.pop();

        for(pair<int, int> v : adj(u, n, m))
        {
            if(dist[v.first][v.second]==inf && a[v.first][v.second]!='#')
            {
                q.push(v);
                dist[v.first][v.second] = dist[u.first][u.second]+1;
                par[v.first][v.second] = u;
            }
        }
    }

    //for(int i=0;i<n;i++)
    //{
    //    for(int j=0;j<m;j++)
    //    {
    //        cout<<dist_mon[i][j]<<" ";
    //    }
    //    cout<<endl;
    //}
    //cout<<endl;
    //for(int i=0;i<n;i++)
    //{
    //    for(int j=0;j<m;j++)
    //    {
    //        cout<<dist[i][j]<<" ";
    //    }
    //    cout<<endl;
    //}

    pair<int, int> destination = {inf, inf};
    for(int i=0;i<m;i++)
    {
        if(a[0][i]=='.' && dist_mon[0][i]>dist[0][i])
        {
            destination = {0,i};
            break;
        }
        if(a[n-1][i]=='.' && dist_mon[n-1][i]>dist[n-1][i])
        {
            destination = {n-1,i};
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i][0]=='.' && dist_mon[i][0]>dist[i][0])
        {
            destination = {i,0};
            break;
        }
        if(a[i][m-1]=='.' && dist_mon[i][m-1]>dist[i][m-1])
        {
            destination = {i,m-1};
        }
    }

    //cout<<"destination is: "<<destination.first+1<<" "<<destination.second+1<<endl;
    
    if(f==1)
    {
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return 0;
    }

    if(destination.first==inf)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;

    vector<pair<int, int>> path;
    path.push_back(destination);

    while(par[destination.first][destination.second]!=destination)
    {
        destination = par[destination.first][destination.second];
        path.push_back(destination);
    }
    reverse(path.begin(), path.end());

    string s;
    for(int i=1;i<sz(path);i++)
    {
        if(path[i].first < path[i-1].first) s.push_back('U');
        else if(path[i].first > path[i-1].first) s.push_back('D');
        else if(path[i].second < path[i-1].second) s.push_back('L');
        else if(path[i].second > path[i-1].second) s.push_back('R');
    }

    cout<<sz(s)<<endl;
    cout<<s<<endl;

    auto stopTime = curTime();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
