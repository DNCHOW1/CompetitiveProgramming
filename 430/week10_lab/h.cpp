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

void traverse(v64& dp, v64& costs, ll curr){
    v64 out;
    while(curr != 0){
        // dbg(curr);
        out.pb(dp[curr]);
        curr -= costs[dp[curr]];
    }

    for(auto it = out.rbegin(); it != out.rend(); it++){
        cout << (*it + 1) << " ";
    }
    cout << endl;
}

int main(){
    ll n; cin >> n;
    v64 arr(n);
    for(ll i = 0; i < n; i++) cin >> arr[i];

    ll m; cin >> m;
    v64 orders(m);
    for(ll i = 0; i < m; i++) cin >> orders[i];

    v64 ways(30005, 0);
    // vv64 dp(30005, v64(n+1, -1));
    v64 dp(30005, -1);
    ways[0] = 1;
    // dp[0][0] = 0;
    dp[0] = 0;
    for(ll j = 0; j < n; j++){
        for(ll i = 1; i <= 30000; i++){
            if(i - arr[j] >= 0 && ways[i-arr[j]] > 0){
                ways[i] += ways[i-arr[j]];
                // calc dp path
                dp[i] = j;
            }
        }
    }

    for(auto num: orders){
        if(ways[num] == 0) cout << "Impossible" << endl;
        else if(ways[num] != 1) cout << "Ambiguous" << endl;
        else{
            traverse(dp, arr, num);
        }
    }
    return 0;
}