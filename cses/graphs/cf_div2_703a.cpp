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

/*
3
0 0 0
3
0 0 1
3
0 0 2
3
0 0 3
3
0 0 4
3
0 0 5
3
0 1 0
*/

string solve(){
    bool flag = false;
    ll n; cin >> n;
    ll extra = 0;
    for(ll i = 0; i < n; i++){
        ll m; cin >> m;
        if(m + extra < i) {
            flag = true;
                                    // (m - i) + extra < 0, bad!
                                    // MISTAKE WITH AN EARLY RETURN!! DOESN'T READ IN EVERYTHING YET!!
        }
        else{
            extra += (m - i); // must be >= 0
        }
    }
    if(flag) return "NO";
    return "YES";
}

void solve2() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    long long sum = 0, need = 0;
    for (int i = 0; i < n; ++i) {
        need += i;
        sum += a[i];
        if (sum < need) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main(){
    int t; cin >> t;
    // for(int i = 0; i < t; i++){
    //     dbg(i);
    //     int n; cin >> n;
    //     v32 a(n);
    //     for(auto &x: a) cin >> x;
    //     if(i >= 43 && i <= 45) dbg(a);
    // }
    while(t--) cout << solve() << endl;
    // while(t--) solve2();
    return 0;
}