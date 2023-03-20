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

// RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
// RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR

void solve(){
    int n, r, b; cin >> n >> r >> b;
    int p = r/(b + 1), q = r%(b + 1); // The floor of the first is the lower bound of each group,
                                    // modulo is how many groups should have an extra
    // cout << p << " " << q << endl;
    // cout << string("r", 3) << endl;
    for(int i = 0; i < q; i++){
        cout << string(p + 1, 'R') << "B";
    }
    for(int i = q; i < b; i++){
        cout << string(p, 'R') << "B";
    }
    cout << string(p, 'R');
    cout << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}