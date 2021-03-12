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

struct node
{
    bool isEndOfWord = false;
    unordered_map<char, struct node*> mp;
};

struct node* makeNode()
{
    struct node* new_node = new node;
    return new_node;
}

struct node* root;

void insert(string s)
{
    struct node* temp = root;
    for(int i=0;i<sz(s);i++)
    {
        if(temp->mp[s[i]]==NULL)
        {
            temp->mp[s[i]] = makeNode();
        }

        temp = temp->mp[s[i]];
    }
    temp->isEndOfWord = true;
}

signed main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    auto startTime = curTime();

    string s;
    cin>>s;

    int n = sz(s);
    int k;
    cin>>k;

    root = makeNode();

    vector<string> a(k);
    for(int i=0;i<k;i++)
    {
        cin>>a[i];
        insert(a[i]);
    }

    vector<vector<int>> jumps(n);
    for(int i=0;i<n;i++)
    {
        struct node* temp = root;
        for(int j=i;j<n;j++)
        {
            if(temp->mp[s[j]]!=nullptr) temp = temp->mp[s[j]];
            else break;
            if(temp->isEndOfWord) jumps[i].push_back(j+1);
        }
    }

    vector<int> dp(n+1);
    dp[n]=1;
    for(int i=n-1;i>=0;i--)
    {
        for(int j : jumps[i])
        {
            dp[i]=(dp[i]+dp[j])%mod;
        }

        if(sz(jumps[i])==0) dp[i]=0;
    }

    cout<<dp[0]<<endl;

    auto stopTime = curTime();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
