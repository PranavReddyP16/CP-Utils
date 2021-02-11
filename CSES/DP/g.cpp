#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
using namespace std::chrono;

#define ll long long
#define ld long double
#define pq priority_queue
#define ff first
#define ss second
#define pb push_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(c) ((ll)c.size())
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int ll

#ifdef LL
const ll inf = 1e9;
#else 
const ll inf = 1e18;
#endif

const int mod = 1e9 + 7;
const int mod2 = 998244353;

typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

// lower bound returns first element greater than the value

high_resolution_clock::time_point curTime() { return high_resolution_clock::now(); }
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);} //Just add this as a third argument to sort() while sorting an array of pairs; NO NEED FOR ANY ARGUMENTS;
template <typename T>
T fact(T a, T modulus){ int res = 1, i; for (i = 2; i <= a; i++){ res *= i; res%=modulus;} return res; }
template <typename T>
ll powmod(T a,T b,ll m){ ll ans=1; while(b>0){if(b&1){ans*=a;ans%=m;}a*=a;a%=m;b>>=1;} return ans; }
template <typename T>
ll power(T a, T b){ ll ans=1; while(b>0){if(b&1){ans*=a;}a*=a;b>>=1;}return ans;}
template <typename T>
T gcd(T a,T b){ return (b?__gcd(a,b):a); }
template <typename T>
T lcm(T a, T b){ return (a*(b/gcd(a,b))); }
template <typename T>
T cl(T a, T b){ return (a+b-1)/b; }
template <typename T>
T set_bits(T a)
{ return __builtin_popcount(a); }
template <typename T>
T add_self(T& a, T b, T modulus){ a+=b; if(a>=modulus){ a-=modulus; } }
template <typename T>
T to_upper(T s){ transform(s.begin(), s.end(), s.begin(), ::toupper); return s; }
template <typename T>
T to_lower(T s){ transform(s.begin(), s.end(), s.begin(), ::tolower); return s; }

#define rep(i,n) for(long long i=0;i<n;i++)



signed main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    auto startTime = curTime();

    long long n,x;
    cin>>n>>x;

    vector<long long> h(n), s(n);
    for(long long i=0;i<n;i++)
    {
        cin>>h[i];
    }
    for(long long i=0;i<n;i++)
    {
        cin>>s[i];
    }

    //vector<vector<long long>> dp(n+1, vector<long long> (x+1, -1));
    //rep(i,n+1) dp[i][0] = 0;

    //cur[i] is the max pages for the current element where the total value is i
    vector<int> prev(x+1, -1);
    prev[0] = 0;
    for(long long i=1;i<=n;i++)
    {
        vector<int> cur(x+1);
        for(long long j=1;j<=x;j++)
        {
            if(j==h[i-1]) cur[j] = s[i-1];
            if(j>h[i-1] && prev[j-h[i-1]] != -1) cur[j] = max(prev[j], prev[j-h[i-1]]+s[i-1]);
            else cur[j] = max(cur[j], prev[j]);
        }

        prev = cur;
    }


    long long ans=0;
    for(long long i=0;i<=x;i++)
    {
        ans = max(ans, prev[i]);
    }

    cout<<ans<<endl;

    auto stopTime = curTime();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
