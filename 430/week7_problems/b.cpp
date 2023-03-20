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
// Didn't know how to invalidate paths where k remaining
//  figured out that if everything initialized to -1e9, prev paths would be invalid if they can't use all k's

ll mat[305][2] = {};
ll dp[305][305][3] = {}; // row is the blocks left, col is pos, z is (no block, block left, block right)

int main(){
    ll n, k;
    while(cin >> n >> k){
        if(n == 0) break;

        for(int i = 0; i <= k; i++){
            for(int j = 0; j <= n+2; j++){
                for(int a = 0; a < 3; a++) dp[i][j][a] = -1e9;
            }
        }

        dp[0][1][0] = dp[0][1][1] = dp[0][1][2] = 0;
        for(int i = 2; i < n+2; i++){
            cin >> mat[i][0] >> mat[i][1];
            ll sm = mat[i][0]+mat[i][1];
            dp[0][i][0] = dp[0][i][1] = dp[0][i][2] = sm+dp[0][i-1][0];
        }

        for(int i = 1; i <= k; i++){
            for(int j = 2; j < n+2; j++){
                if(j < i+1) continue;

                dp[i][j][0] = max({dp[i][j-1][0], dp[i][j-1][1], dp[i][j-1][2]})+mat[j][0]+mat[j][1]; // not blocking current
                dp[i][j][1] = max({dp[i-1][j-1][0], dp[i-1][j-1][1], dp[i-1][j-2][2]})+mat[j][1]; // blocking left
                dp[i][j][2] = max({dp[i-1][j-1][0], dp[i-1][j-2][1], dp[i-1][j-1][2]})+mat[j][0]; // blocking right
            }
        }

        cout << max({dp[k][n+1][0], dp[k][n+1][1], dp[k][n+1][2]}) << endl;
    }
    return 0;
}