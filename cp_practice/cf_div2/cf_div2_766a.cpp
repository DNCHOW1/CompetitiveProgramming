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

int solve(){
    int n, m, r, c; cin >> n >> m >> r >> c;
    r--; c--;
    int b = 0;
    vector<string> a(n);
    for(auto &x: a) {
        cin >> x;
        for(auto &y: x){
            b += (y == 'B');
        }
    }
    
    if(b == 0) return -1;
    if(a[r][c] == 'B') return 0;
    for(int i = 0; i < n; i++){
        if(a[i][c] == 'B') return 1;
    }
    for(int i = 0; i < m; i++){
        if(a[r][i] == 'B') return 1;
    }
    return 2;
}

int main(){
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        cout << solve() << endl;
    }
    return 0;
}