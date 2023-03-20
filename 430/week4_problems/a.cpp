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

struct DSU{
    v64 dsu;
    DSU(ll n) { dsu = v64(n, -1); }

    ll get(ll x){ return (dsu[x] < 0) ? x: dsu[x] = get(dsu[x]); }

    ll size(ll x) { return -dsu[get(x)]; }

    void unite(ll a, ll b){
        ll x = get(a), y = get(b);
        if(x == y) return;
        if(dsu[y] > dsu[x]) swap(x, y);

        dsu[x] += dsu[y];
        dsu[y] = x;
    }
};

int main(){
    ll n, cnt = 0; cin >> n;
    DSU dsu(500001);
    while(n--){
        ll m; cin >> m;
        v64 temp(m);
        set<ll> seen;
        ll sum = 0;
        for(ll i = 0; i < m; i++) {
            cin >> temp[i];
            ll repr = dsu.get(temp[i]);
            if(seen.count(repr) == 0) {
                seen.insert(repr);
                sum += dsu.size(repr);
            }
        }
        if(sum == m){
            cnt++;
            for(auto num: temp) dsu.unite(temp[0], num);
        }
    }
    cout << cnt << endl;
    return 0;
}