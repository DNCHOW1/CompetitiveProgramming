#include <bits/stdc++.h>  
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define nl '\n'
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& pair) {
    return out << '(' << pair.first << ", " << pair.second << ')';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
    if(vec.empty()) return out << "[]";
    out << '[';
    for(size_t i = 0; i < vec.size()-1; i++) out << vec.at(i) << ", ";
    return out << vec.back() << ']';
}
ll INF = 2e18;
ll MOD9 = 998244353;
ll MOD1 = 1e9 + 7;

void dfs(v64& cost, vv64& dp, int pos, int step, ll curr){
// void dfs(v64& cost, v64& dp, int pos, int step, ll curr){
    if(pos >= cost.size() || pos < 0 || step >= cost.size() + 1){
        return;
    }
    // if curr > dp[pos] return immediately
    curr += cost[pos];
    if(curr > dp[pos][step]) return;
    dp[pos][step] = min(dp[pos][step], curr);
    dfs(cost, dp, pos+step+1, step+1, curr); // going forward
    dfs(cost, dp, pos-step, step, curr); // backward
}

int main(){
    ll n; cin >> n;
    v64 cost(n);
    // v64 dp(n+1, 10000000000000LL);
    vv64 dp(n+1, v64(1005, 1e18));
    for(int i = 0; i < n; i++) cin >> cost[i];

    dfs(cost, dp, 1, 1, 0);
    ll mn = 1e18;
    for(int i = 0; i < 1004; i++){
        mn = min(mn, dp[n-1][i]);
    }
    cout << mn << endl;
    return 0;
}