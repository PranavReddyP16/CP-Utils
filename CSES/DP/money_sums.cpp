#pragma GCC optimize("Ofast")

#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
using namespace std::chrono;

#define int long long
#define ld long double
#define sz(c) ((int)c.size())
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const int inf = 1e18;

const int mod = 1e9 + 7;
const int mod2 = 998244353;



signed main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    auto startTime = high_resolution_clock::now();

    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a.begin(), a.end());

    int N = 1e5+5;
    vector<vector<int>> dp(n, vector<int> (N));

    for(int j=1;j<N;j++) {
        for(int i=0;i<n;i++) {
            if(a[i]==j) {
                dp[i][j] = 1;
            }
            else {
                if(i>0 && j>=a[i]) dp[i][j] |= dp[i-1][j-a[i]];
                if(i>0) dp[i][j] |= dp[i-1][j];
            }
        }
    }
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<10;j++) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }

    vector<int> ans;
    for(int i=0;i<N;i++) {
        for(int j=0;j<n;j++) {
            if(dp[j][i]) {
                ans.push_back(i);
                break;
            }
        }
    }

    cout<<sz(ans)<<endl;
    for(int i=0;i<sz(ans);i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
