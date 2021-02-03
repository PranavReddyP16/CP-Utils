#include <bits/stdc++.h>
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

vector<vector<int>> adj;
vector<vector<int>> steps;
vector<int> vis;
vector<int> height;

int bits(int n)
{
    int cnt=0;
    while(n)
    {
        n>>=1;
        cnt++;
    }
    return cnt;
}

void dfs(int u)
{
    vis[u]=1;
    for(int v : adj[u])
    {
        if(!vis[v])
        {
            height[v] = height[u]+1;
            dfs(v);
            steps[0][v] = u;
        }
    }
}

int walk(int u, int n)
{
    int ans = u;;

    int cnt=0;
    while(n)
    {
        if(n&1)
        {
            ans = steps[cnt][ans];
        }

        cnt++;
        n>>=1;
    }

    return ans;
}

signed main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    auto startTime = curTime();

    int n;
    cin>>n;
    int m = bits(n);

    adj.resize(n);
    vis.resize(n);
    steps.resize(m, vector<int> (n));
    height.resize(n);

    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        u--;v--;

        adj[u].push_back(v);
        adj[v].push_back(v);
    }

    dfs(0);
    steps[0][0]=0;
    //for(int i=0;i<n;i++) cout<<height[i]<<" ";
    //cout<<endl;

    for(int i=1;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            steps[i][j] = steps[i-1][steps[i-1][j]];
        }
    }

    cout<<"Enter two nodes to find the LCA of:"<<endl;
    int a,b;
    cin>>a>>b;
    a--;b--;

    if(height[a]<height[b]) swap(a,b);

    a = walk(a, height[a]-height[b]);
    if(a==b)
    {
        cout<<a+1<<endl;
        return 0;
    }

    int ans=0;
    for(int i=m-1;i>=0;i--)
    {
        if(walk(a,(1<<i) + ans) != walk(b,(1<<i) + ans)) ans += (1<<i);
    }

    cout<<walk(a, ans+1)+1<<endl;

    auto stopTime = curTime();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
