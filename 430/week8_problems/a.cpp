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

// Reflections:
// * Tried approaching like 1D dp, didn't work because it didn't account for all possibilities
//      Case: (Skip 1, Eat 2, Eat 3) - 83 is never tried because at index 2 because of (Eat, Eat, Eat) - 88
//        4 54
//        28 68 29 52
//        107
// * Why can't approach this like "narrow art galaries"?
//    My current approach actually isn't like narrow art galaries. I treat like 1D dp with 3 possible states
// * To perform tabulation, needed key insight that LEVELS OF M ARE PART OF THE STATES!!!!
//    Because m is multiplied by (2/3)^k, it has a certain amount of levels. That means that paths you take can
//    converge at some dp[i][m'], which means at this state you take the max!
//    NOTE: This is why the recursive solution also works
// * When implementing solution, FORGOT ABOUT LEVEL==0 should account for dp[i-2][0]

// dp[i][0] = max{dp[i-3][...]} + min(levels[0], cal[i]) (WHEN LEVEL == 0)
// dp[i][level] = max{dp[i-2][level], dp[i-1][level-1]} + min(levels[level], cal[i]) (WHEN LEVEL != 0)
int main(){
    ll n, m; cin >> n >> m;
    ll temp = m;
    v64 levels;
    while(temp){
        levels.pb(temp);
        temp = temp*2/3;
    }

    v64 calories(n);
    vv64 dp(n+4, v64(levels.size()+1));
    for(ll i = 0; i < n; i++) cin >> calories[i];

    // Trying out tabulation
    for(ll i = 3; i <= n+3; i++){
        for(ll level = 0; level < dp[0].size(); level++){
            if(level == 0){
                for(ll tmp = 0; tmp < dp[0].size(); tmp++) dp[i][level] = max(dp[i][level], dp[i-3][tmp]);
                dp[i][level] = max(dp[i][level], dp[i-2][level]);
            } else{
                dp[i][level] = max(dp[i-2][level], dp[i-1][level-1]);
            }
            dp[i][level] += min(levels[level], calories[i-3]);
        }
    }

    ll out = -1e9;
    for(ll lvl = 0; lvl < dp[0].size(); lvl++) out = max(out, dp[n+2][lvl]);
    cout << out << endl;
    return 0;
}