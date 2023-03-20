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

ll dp[3005][3005]{};

int main(){
    int n; cin >> n;
    v64 a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;

    for(int i = 0; i < n; i++){
        if(i == 0){
            dp[i][a[i]] = 1;
            for(int j = a[i]+1; j <= b[i]; j++){
                dp[i][j] = (1+dp[i][j-1])%MOD9;
            }
            for(int j = b[i]+1; j <= 3000; j++) dp[i][j] = dp[i][j-1]%MOD9;
        } else{
            for(int j = a[i]; j <= b[i]; j++){
                dp[i][j] = (dp[i][j-1]%MOD9 + dp[i-1][j]%MOD9) % MOD9;
            }
            for(int j = b[i]+1; j <= 3000; j++) dp[i][j] = dp[i][j-1]%MOD9;
        }
    }
    
    cout << dp[n-1][b.back()] << endl;
    return 0;
}