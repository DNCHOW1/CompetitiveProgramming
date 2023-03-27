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

vv64 dp(1000009, {-1, -1});
v64 used(1000009);

ll dfs(v64& arr, ll stones, ll player){
    // if(stones == 0) return (player == 1) ? 2 : 1;
    if(used[stones] == 1) return player;
    else if(dp[stones][player-1] != -1) return dp[stones][player-1];
    // dp[stones] != {-1, -1}

    // run dfs top-down
    for(ll i = 0; i < arr.size(); i++){
        if(stones-arr[i] > 0){
            auto winner = dfs(arr, stones-arr[i], (player == 1) ? 2 : 1);
            if(winner != -1){
                if(winner == player) {
                    dp[stones][player-1] = player;
                    return player;
                }
                else if(dp[stones][player-1] == -1) dp[stones][player-1] = winner;
            }
        }
    }
    return dp[stones][player-1];
}

int main(){
    ll n;
    while(cin >> n){
        if(cin.eof()) break;
        ll m; cin >> m;
        v64 arr(m);
        for(ll i = 0; i < m; i++){
            cin >> arr[i];
            used[arr[i]] = 1;
        }
        sort(arr.begin(), arr.end(), greater());

        for(ll i = 0; i < n+5; i++) dp[i] = {-1, -1};
        dfs(arr, n, 1);

        for(auto num: arr) used[num] = 0;
        if(dp[n][0] == 1) cout << "Stan wins" << endl;
        else cout << "Ollie wins" << endl;
    }
    return 0;
}