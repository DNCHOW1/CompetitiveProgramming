#include <bits/stdc++.h>  
 
using namespace std;
 
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

ll dp[52][2502]{};

int main(){
    int n, m, k; cin >> n >> m >> k;
    dp[0][0] = 1;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n*m; j++){
            // on each i, j -> only go up to m

            for(int b = 1; b+j <= m; b++){
                dp[i+1][j+b] += (dp[i][j])%MOD9;
                dp[i+1][j+b] %= MOD9;
            }
        }
    }
    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= k; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    ll tot = 0;
    for(int i = 0; i <= k; i++){
        tot += dp[n][i];
        tot %= MOD9;
    }
    cout << tot << endl;
    return 0;
}