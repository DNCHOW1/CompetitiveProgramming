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

void solve(){
    ll n; cin >> n;
    v64 arr(n+1);
    ll sm = 0;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        sm += arr[i];
    }

    vv64 dp(n+5, v64(sm+5, 1e18)); // row is index in arr, col is height; store the min heights
    vector<vector<char>> choices(n+5, vector<char>(sm+5, '*'));
    dp[0][0] = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j <= sm; j++){
            if(j+arr[i] <= sm){ // Up
                ll tmpMxHeight = max(dp[i][j], j+arr[i]);
                if(tmpMxHeight < dp[i+1][j+arr[i]]){
                    dp[i+1][j+arr[i]] = tmpMxHeight;
                    choices[i+1][j+arr[i]] = 'U';
                }
            }
            if(j-arr[i] >= 0){ // Down
                ll tmpMxHeight = max(dp[i][j], j-arr[i]);
                if(tmpMxHeight < dp[i+1][j-arr[i]]){
                    dp[i+1][j-arr[i]] = tmpMxHeight;
                    choices[i+1][j-arr[i]] = 'D';
                }
            }
        }
    }

    // cout directions with trace if last != 1e18
    if(dp[n][0] == 1e18) cout << "IMPOSSIBLE" << endl;
    else{
        vector<char> out;
        ll curr = 0;
        for(ll i = n; i >= 1; i--){
            out.pb(choices[i][curr]);
            if(out.back() == 'U') curr -= arr[i-1];
            else curr += arr[i-1];
        }

        reverse(out.begin(), out.end());
        for(auto c: out) cout << c;
        cout << endl;
    }
}

int main(){
    ll t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}