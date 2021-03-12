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

vector<int> t;
int n;

void update(int pos, int val)
{
    pos+=n;
    t[pos] -= val;
    for(pos>>=1;pos>0;pos>>=1)
    {
        t[pos] = max(t[pos<<1],t[pos<<1|1]);
    }
}

int query(int l, int r)
{
    int ans=0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1) ans = max(ans, t[l++]);
        if(r%2==0) ans = max(ans, t[r--]);
    }

    if(l==r) ans = max(ans, t[l]);

    return ans;
}

signed main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    auto startTime = curTime();

    int m;
    cin>>n>>m;

    t.resize(2*n);

    vector<int> h(n),r(m);
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
        t[i+n] = h[i];
    }

    for(int i=0;i<m;i++)
    {
        cin>>r[i];
    }

    for(int i=n-1;i>0;i--)
    {
        t[i] = max(t[i<<1], t[i<<1|1]);
    }

    for(int i=0;i<m;i++)
    {
        if(query(0,n-1)<r[i])
        {
            cout<<0<<" ";
            continue;
        }

        int x=0,y=n-1;
        while(x<y)
        {
            int mid = (x+y)/2;

            if(query(0,mid)<r[i]) x=mid+1;
            else y = mid;
        }

        //x++;
        cout<<x+1<<" ";
        update(x, r[i]);
    }
    cout<<endl;

    auto stopTime = curTime();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
