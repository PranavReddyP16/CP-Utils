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

vector<vector<pair<int, int>>> par;
vector<vector<int>> siz;

pair<int, int> find(pair<int, int> a)
{
    while(par[a.first][a.second]!=make_pair(a.first, a.second)) a = par[a.first][a.second];
    return a;
}

void merge(pair<int, int> a, pair<int, int> b)
{
    a = find(a);
    b = find(b);

    if(siz[a.first][a.second] < siz[b.first][b.second]) swap(a,b);
    par[b.first][b.second] = a;
    siz[a.first][a.second] += siz[b.first][b.second];
}

signed main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    auto startTime = curTime();

    int n,m;
    cin>>n>>m;

    par.resize(n, vector<pair<int, int>>(m));
    siz.resize(n, vector<int> (m));

    vector<string> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            par[i][j] = {i,j};
            siz[i][j]=1;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='#') continue;
            if(i>0 && a[i-1][j]=='.')
            {
                merge({i,j}, {i-1,j});
            }
            if(i<n-1 && a[i+1][j]=='.')
            {
                merge({i,j}, {i+1,j});
            }
            if(j>0 && a[i][j-1]=='.')
            {
                merge({i,j}, {i,j-1});
            }
            if(j<n-1 && a[i][j+1]=='.')
            {
                merge({i,j}, {i,j+1});
            }
        }
    }

    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(par[i][j] == make_pair(i,j) && a[i][j]=='.') cnt++;
        }
    }

    cout<<cnt<<endl;

    auto stopTime = curTime();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
