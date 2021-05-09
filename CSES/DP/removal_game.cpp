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

    vector<int> a(n);
    int sum=0;
    vector<int> pref(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        
        if(i==0) pref[i]=a[i];
        else pref[i] = pref[i-1]+a[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, -inf));

    for(int len=0;len<n;len++)
    {
        for(int i=0;i<n;i++)
        {
            int j = len+i;
            if(j<0 || j>=n) continue;

            if(i==j) dp[i][j] = a[i];
            else
            {
                if(i<n-1) dp[i][j] = max(pref[j]-pref[i+1]+a[i+1]-dp[i+1][j]+a[i], dp[i][j]);
                if(j>0) dp[i][j] = max(pref[j-1]-pref[i]+a[i]-dp[i][j-1]+a[j], dp[i][j]);
            }
        }
    }

    //for(int i=0;i<n;i++)
    //{
    //    for(int j=0;j<n;j++) cout<<dp[i][j]<<" ";
    //    cout<<endl;
    //}

    cout<<dp[0][n-1]<<endl;

    auto stopTime = curTime();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
