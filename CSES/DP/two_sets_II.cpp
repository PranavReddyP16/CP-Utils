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

int power(int x, int y)
{
    if (y == 0)
        return 1;
    int p = power(x, y / 2) % mod;
    p = (p * p) % mod;
 
    return (y % 2 == 0) ? p : (x * p) % mod;
}

signed main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    auto startTime = curTime();

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++) a[i] = i+1;

    int sum = (n*(n+1))/2;
    if(sum%2)
    {
        cout<<0<<endl;
        return 0;
    }

    sum = sum/2;

    vector<vector<int>> dp(sum+1, vector<int> (n));
    for(int i=1;i<sz(dp);i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==a[j])
            {
                dp[i][j]++;
                dp[i][j]%=mod;
            }

            if(j>0) dp[i][j] = (dp[i][j]+dp[i][j-1])%mod;
            if(i-a[j]>0 && j>0) dp[i][j] = (dp[i][j]+dp[i-a[j]][j-1])%mod;
        }
    }

    //for(int i=1;i<sz(dp);i++)
    //{
    //    cout<<i<<" ";
    //    for(int j=0;j<n;j++) cout<<dp[i][j]<<" ";
    //    cout<<endl;
    //}

    cout<<(dp[sum][n-1]*power(2,mod-2))%mod<<endl;

    auto stopTime = curTime();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
