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
    if(vec.empty()) return out << "[]" << '\n';
    out << '[';
    for(size_t i = 0; i < vec.size()-1; i++) out << vec.at(i) << ", ";
    return out << vec.back() << ']' << '\n';
}
ll INF = 2e18;
ll MOD9 = 998244353;
ll MOD1 = 1e9 + 7;

void add(ll& a, ll b){
    if((a += b) >= MOD1) a -= MOD1;
}

int main(){
    int n, m; cin >> n >> m;
    v32 a(n);
    for(auto &x: a) cin >> x;
    vv64 dp(n, v64(m+1, 0));
    if(a[0] != 0) dp[0][a[0]] = 1;
    else{
        for(int j = 1; j <= m; j++) dp[0][j] = 1;
    }

    for(int i = 1; i < n; i++){
        ll curr = a[i];
        if(curr == 0){
            for(int j = 1; j <= m; j++){
                add(dp[i][j], dp[i-1][j-1]);
                add(dp[i][j], dp[i-1][j]);
                if(j != m) add(dp[i][j], dp[i-1][j+1]);
            }
        } else{
            add(dp[i][curr], dp[i-1][curr-1]);
            add(dp[i][curr], dp[i-1][curr]);
            if(curr != m) add(dp[i][curr], dp[i-1][curr+1]);
        }
    }

    // print out the sum of the last row
    ll total = 0;
    for(int i = 1; i <= m; i++) add(total, dp[n-1][i]);
    cout << total << endl;
    return 0;
}