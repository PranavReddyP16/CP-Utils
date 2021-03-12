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

int n;
//This segment tree is for range updates
vector<int> t;

void update(int l, int r)
{
    int val = -1;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1) t[l++]+=val;
        if(r%2==0) t[r--]+=val;
    }

    if(l==r) t[l]+=val;
}

int query(int pos)
{
    int ans=0;

    for(pos+=n;pos>0;pos>>=1)
    {
        ans += t[pos];
    }

    return ans;
}

signed main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    auto startTime = curTime();

    cin>>n;

    t.resize(2*n);

    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        t[i+n] = i;
    }

    vector<int> p(n);
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }

    for(int i=n-1;i>0;i--)
    {
        //t[i] = t[i<<1]+t[i<<1|1];
    }

    for(int i=0;i<n;i++)
    {
        p[i]--;
        int l=0,r=n-1;

        int res=-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(query(mid)>p[i]) r=mid-1;
            else if(query(mid)<p[i]) l=mid+1;
            else 
            {
                res=mid;
                l=mid+1;
            }
        }

        cout<<a[res]<<" ";
        if(res<n) update(res+1, n-1);
    }
    cout<<endl;

    auto stopTime = curTime();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
