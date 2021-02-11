#include "bits/stdc++.h"
#include <cstdint>
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

#define rep(i,n) for(int i=0;i<n;i++)

struct Point
{
    int x, y;

    void read()
    {
        cin>>x>>y;
    }

    int operator *(const Point &b)
    {
        return x*b.y - y*b.x;
    }

    Point operator -(const Point &b)
    {
        return {x-b.x, y-b.y};
    }
};

signed main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    auto startTime = curTime();

    int tt;
    cin>>tt;
    while(tt--)
    {
        vector<Point> p(4);
        for(int i=0;i<4;i++)
        {
            p[i].read();
        }

        if((p[1]-p[0])*(p[3]-p[2]) == 0)
        {
            if((p[1]-p[0])*(p[2]-p[0]) != 0)
            {
                cout<<"NO"<<endl;
                continue;
            }

            if(
                max(p[0].x, p[1].x) <= min(p[2].x, p[3].x) || max(p[0].y, p[1].y) <= min(p[2].y, p[3].y) ||
                max(p[3].x, p[2].x) <= min(p[1].x, p[0].x) || max(p[3].y, p[2].y) <= min(p[1].y, p[0].y)
                    )
            {
                cout<<"NO"<<endl;
            }
            else cout<<"YES"<<endl;

            continue;
        }

        int c1 = (p[1]-p[0])*(p[2]-p[0]);
        int c2 = (p[1]-p[0])*(p[3]-p[0]);
        int c3 = (p[3]-p[2])*(p[1]-p[2]);
        int c4 = (p[3]-p[2])*(p[0]-p[2]);

        if(c2*c1 <= 0 && c4*c3 <= 0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    auto stopTime = curTime();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
