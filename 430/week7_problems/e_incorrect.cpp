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
    ll m; cin >> m;
    vector<string> res = {"NNN", "NNY", "NYN", "NYY", "YNN", "YNY", "YYN", "YYY"};
    v64 mapping(8);
    vv64 pref(m, v64(8)); // preferences of the priests, lower is higher pref
    for(ll i = 0; i < m; i++){
        for(int j = 0; j < 8; j++) cin >> pref[i][j];
    }
    for(int i = 0; i < 8; i++) mapping[i] = i;

    // logic here
    for(ll i = m-1; i >= 0; i--){
        v64 temp_mapping(8, -1);
        for(ll j = 0; j < 8; j++){
            ll mn = 10;
            for(ll k = 0; k < 3; k++){
                if(temp_mapping[j] == -1 || pref[i][mapping[(1 << k) ^ j]] < mn){
                    temp_mapping[j] = (1 << k) ^ j;
                    mn = pref[i][mapping[(1 << k) ^ j]];
                }
            }
        }
        mapping = move(temp_mapping);
    }

    cout << res[mapping[0]] << endl;
}

int main(){
    ll n; cin >> n;
    while(n--){
        solve();
    }
    return 0;
}