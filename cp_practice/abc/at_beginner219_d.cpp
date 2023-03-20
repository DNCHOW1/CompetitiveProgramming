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

// ll dp[301][301]{};
vv64 dp(301, v64(301, INF));

int main(){
    int n, x, y; cin >> n >> x >> y;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        for(int j = 300; j >= 0; j--){
            for(int k = 300; k >= 0; k--){
                if(j - a <= 0 && k - b <= 0) dp[j][k] = 1;
                else{
                    dp[j][k] = min(dp[j][k], 1+dp[max(0, j-a)][max(k-b, 0)]);
                }
            }
        }
    }
    if(dp[x][y] == INF) cout << -1 << endl;
    else cout << dp[x][y] << endl;
    return 0;
}