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

    int a,b;
    cin>>a>>b;

    vector<vector<int>> dp(a+1, vector<int> (b+1, inf));

    for(int i=0;i<=a;i++)
    {
        for(int j=0;j<=b;j++)
        {
            if(i==j) dp[i][j]=0;
        }
    }

    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            if(i==j) continue;
            int temp = inf;
            for(int k=1;k<=i/2;k++)
            {
                temp = min(temp, dp[i-k][j] + dp[k][j]+1);
            }

            for(int k=1;k<=j/2;k++)
            {
                temp = min(temp, dp[i][j-k]+dp[i][k]+1);
            }

            dp[i][j] = min(dp[i][j], temp);
        }
    }

    //for(int i=1;i<=a;i++)
    //{
    //    for(int j=1;j<=b;j++) cout<<dp[i][j]<<" ";
    //    cout<<endl;
    //}

    cout<<dp[a][b]<<endl;

    auto stopTime = curTime();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
