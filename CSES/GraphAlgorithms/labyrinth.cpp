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
    vector<pair<int, int>> res;
    if(a.first>0) res.push_back({a.first-1, a.second});
    if(a.first<n-1) res.push_back({a.first+1, a.second});
    if(a.second>0) res.push_back({a.first, a.second-1});
    if(a.second<m-1) res.push_back({a.first, a.second+1});

    return res;
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

    vector<vector<int>> vis(n,vector<int> (m));
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m, {-1,-1}));

    int f=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='A')
            {
                vis[i][j] = 1;
                queue<pair<int, int>> q;
                q.push({i,j});

                while(!q.empty())
                {
                    pair<int, int> u = q.front();
                    vis[u.first][u.second]=1;
                    q.pop();

                    for(auto v : adj(u,n,m))
                    {
                        if(vis[v.first][v.second]==0 && (a[v.first][v.second]=='.' || a[v.first][v.second]=='B'))
                        {
                            par[v.first][v.second] = u;
                            vis[v.first][v.second]=1;
                            q.push(v);
                        }
                    }
                }

                f=1;
                break;
            }
        }

        if(f==1) break;
    }

    //for(int i=0;i<n;i++)
    //{
    //    for(int j=0;j<m;j++)
    //    {
    //        cout<<vis[i][j]<<" ";
    //    }
    //    cout<<endl;
    //}

    //cout<<"Nothing\n";
    f=0;
    vector<pair<int, int>> ans;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j] == 'B')
            {
                if(vis[i][j]==0)
                {
                    f=1;
                    break;
                }

                ans.push_back({i,j});
                while(par[i][j].first!=-1 && par[i][j].second!=-1)
                {
                    auto temp = par[i][j];
                    i = temp.first;
                    j = temp.second;
                    ans.push_back({i,j});
                }

                f=2;
                break;
            }
        }

        if(f==1||f==2) break;
    }
    //cout<<"BFS finished"<<endl;

    string s;
    if(f==1)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        cout<<sz(ans)-1<<endl;
        reverse(ans.begin(), ans.end());
        //for(int i=0;i<sz(ans);i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
        for(int i=0;i<sz(ans)-1;i++)
        {
            if(ans[i+1].first>ans[i].first) s.push_back('D');
            if(ans[i+1].first<ans[i].first) s.push_back('U');
            if(ans[i+1].second<ans[i].second) s.push_back('L');
            if(ans[i+1].second>ans[i].second) s.push_back('R');
        }

        cout<<s<<endl;
    }

    auto stopTime = curTime();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
