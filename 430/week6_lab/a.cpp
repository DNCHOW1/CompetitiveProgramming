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



int main(){
    ll r, c; cin >> r >> c;
    ll n; cin >> n;
    set<p64> occ; // O(logn)
    while(n--){
        ll a, b; cin >> a >> b;
        occ.insert({a, b});
    }

    v32 pied(9);
    vp64 dirs = {{-1, -1}, {-1, 0}, {1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}};
    /*
    _ _ _
    _ 0 _
    _ _ _
    */
    for(ll i = 1; i <= r; i++){
        for(ll j = 1; j <= c; j++){
            if(occ.count({i, j}) == 0) continue;
            ll cnt = 0;
            for(auto dr = -1; dr <= 1; dr++){
                for(auto dc = -1; dc <= 1; dc++){
                    if(dr == 0 && dc == 0) continue;
                    ll nr = dr+i, nc = dc+j;
                    cnt += occ.count({nr, nc});
                }
            }
            // for(auto& [dr, dc]: dirs){
            //     ll nr = dr+i, nc = dc+j;
            //     cnt += occ.count({nr, nc});
            // }
            pied[cnt]++;
        }
    }
    for(ll i = 0; i <= 8; i++) cout << pied[i] << " ";
    cout << endl;
    return 0;
}