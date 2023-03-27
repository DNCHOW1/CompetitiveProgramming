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

void solve(){
    ll n, m; cin >> n >> m;
    ll tot = 0;
    map<ll, ll> cnt;
    vector<pair<v64, ll>> prizes;
    for(ll i = 0; i < n; i++){
        ll k, cost; cin >> k;
        v64 tmp;
        while(k--){
            ll prize; cin >> prize;
            tmp.pb(prize);
        }
        cin >> cost;
        prizes.pb({tmp, cost});
    }
    for(ll j = 1; j <= m; j++){
        ll p; cin >> p;
        cnt[j] = p;
    }

    for(auto& [ps, cost]: prizes){
        ll mn = 1e9;
        for(auto p: ps) mn = min(mn, cnt[p]);
        tot += mn*cost;
    }
    cout << tot << endl;
}

int main(){
    ll t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}