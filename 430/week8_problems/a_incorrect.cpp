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

ll dp[115][3] = {};
ll choice[115][3] = {};

int main(){
    ll n, m; cin >> n >> m;
    v64 arr(n);
    for(ll i = 0; i < n; i++) cin >> arr[i];

    choice[2][0] = choice[2][1] = choice[2][2] = m;

    // access arr with arr[i-3]
    for(ll i = 3; i < n+3; i++){
        for(int j = 0; j < 3; j++){
            double choose1 = min(choice[i-1][j], arr[i-3]);
            ll choose2 = min(choice[i-2-(j==0)][j], arr[i-3]);
            if(choose1 + dp[i-1][j] > dp[i][0]){
                dp[i][0] = choose1 + dp[i-1][j];
                choice[i][0] = choice[i-1][j]*2.0/3.0;
            }
            if(choose2 + dp[i-2][j] > dp[i][1] && i >= 4){
                dp[i][1] = choose2 + dp[i-2][j];
                choice[i][1] = choice[i-2-(j==0)][j]*2.0/3.0;
            }
            if(i >= 5) dp[i][2] = max(dp[i][2], dp[i-3][j]);
        }
        if(i >= 5){

        choice[i][2] = m;
        dp[i][2] += min(m, arr[i-3]);
        }
        dbg(dp[i][0]);
        dbg(dp[i][1]);
        dbg(dp[i][2]);
    }
    cout << max({dp[n+2][0], dp[n+2][1], dp[n+2][2]}) << endl;
    return 0;
}