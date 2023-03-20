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

// REFLECTIONS:
// We want to be propogating the result up instead of storing the voting candidates
// This is because the recur stack returns the voting candidates and makes the pref decision wonky
// tunnel-visioned idea of storing dp decisions in 2d arr
//  STORE FINAL RESULT, NOT DECISIONS

vector<string> res = {"NNN", "NNY", "NYN", "NYY", "YNN", "YNY", "YYN", "YYY"};
v64 mapping(8);

ll dfs(vv64& pref, vv64& dp, int row, int vote){
    if(row == pref.size()){
        return vote;
    } else if(dp[row][vote] != -1){
        return dp[row][vote];
    }

    ll mn = 1e9;
    ll final_result = -1;
    // assuming vote is what we have currently, we choose the max of the 3 paths
    for(int i = 0; i < 3; i++){
        ll result = dfs(pref, dp, row+1, vote^(1 << i));
        if(pref[row][result] < mn){
            mn = pref[row][result];
            final_result = result;
        }
    }

    // memo the result in dp
    // save and return result instead of candidate
    dp[row][vote] = final_result;
    return final_result;
}

void solve(){
    ll m; cin >> m;
    vv64 pref(m, v64(8)); // preferences of the priests, lower is higher pref
    vv64 dp(m, v64(8, -1));
    for(ll i = 0; i < m; i++){
        for(int j = 0; j < 8; j++) cin >> pref[i][j];
    }
    for(int i = 0; i < 8; i++) mapping[i] = i;

    cout << res[dfs(pref, dp, 0, 0)] << endl;
}

int main(){
    ll n; cin >> n;
    while(n--){
        solve();
    }
    return 0;
}