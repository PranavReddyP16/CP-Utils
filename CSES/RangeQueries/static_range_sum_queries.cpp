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

    int n,q;
    cin>>n>>q;

    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    vector<int> pref(n);
    for(int i=0;i<n;i++)
    {
        if(i==0) pref[i] = a[i];
        else pref[i] = pref[i-1]+a[i];
    }

    while(q--)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;

        cout<<pref[y]-pref[x]+a[x]<<endl;
    }

    auto stopTime = curTime();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
