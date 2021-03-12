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



signed main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    auto startTime = curTime();

    int n;
    cin>>n;
    int q;
    cin>>q;

    vector<string> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    vector<vector<int>> dp(n, vector<int> (n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0 && j==0)
            {
                dp[i][j] = (a[i][j]=='*'? 1 : 0);
                continue;
            }

            if(i==0) dp[i][j] = dp[i][j-1]+(a[i][j]=='*'? 1 : 0);
            if(j==0) dp[i][j] = dp[i-1][j]+(a[i][j]=='*'? 1 : 0);

            if(i>0&&j>0)
            {
                dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1] + (a[i][j]=='*'?1:0);
            }
        }
    }

    while(q--)
    {
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        y1--;
        x1--;
        y2--;
        x2--;

        int ans=0;
        ans += dp[x2][y2];
        if(x1>0) ans -= dp[x1-1][y2];
        if(y1>0) ans -= dp[x2][y1-1];
        if(x1*y1>0) ans += dp[x1-1][y1-1];

        cout<<ans<<endl;
    }

    auto stopTime = curTime();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
