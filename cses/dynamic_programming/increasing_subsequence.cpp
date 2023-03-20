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
    if(vec.empty()) return out << "[]";
    out << '[';
    for(size_t i = 0; i < vec.size()-1; i++) out << vec.at(i) << ", ";
    return out << vec.back() << ']';
}
ll INF = 2e18;
ll MOD9 = 998244353;
ll MOD1 = 1e9 + 7;



int main(){
    int n; cin >>n;
    v32 a(n);
    for(auto &x: a) cin >> x;
    v32 dp(n, 1);
    int mx = 1;



    // Solution below runs in O(n^2) time, however a time of O(nlogn) is possible
    // for(int i = 1; i < n; i++){
    //     for(int j = i-1; j >= 0; j--){
    //         if(a[j] < a[i]) dp[i] = max(dp[i], dp[j]+1);
    //     }
    //     mx = max(mx, dp[i]);
    // }
    // dbg(dp);
    // cout << mx << endl;
    return 0;
}