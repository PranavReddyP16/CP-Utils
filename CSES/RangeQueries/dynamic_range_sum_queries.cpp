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
vector<int> t;

void update(int pos, int val)
{
    t[pos+n] = val;
    for(pos=(pos+n)>>1;pos>0;pos>>=1)
    {
        t[pos] = t[pos<<1] + t[pos<<1|1];
    }
}

int query(int l, int r)
{
    int ans=0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1) ans += t[l++];
        if(r%2==0) ans += t[r--];
    }

    if(l==r) ans+=t[l];

    return ans;
}

signed main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    auto startTime = curTime();

    int q;
    cin>>n>>q;

    t.resize(2*n);

    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>t[i+n];
    }

    for(int i=n-1;i>0;i--)
    {
        t[i] = t[i<<1]+t[i<<1|1];
    }

    while(q--)
    {
        int x;
        cin>>x;

        if(x==1)
        {
            int pos, val;
            cin>>pos>>val;
            pos--;

            update(pos, val);
        }

        else
        {
            int l,r;
            cin>>l>>r;
            l--;r--;

            cout<<query(l,r)<<endl;
        }
    }

    auto stopTime = curTime();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
