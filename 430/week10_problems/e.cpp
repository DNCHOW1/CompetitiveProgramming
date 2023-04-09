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

struct DSU {
    map<p64, p64> e;
    map<p64, p64> mapp;
    DSU(ll r, ll c) {
        for(ll i = 0; i <= r; i++){
            for(ll j = 0; j <= c; j++){
                e[{i, j}] = {-1, -1};
                mapp[{i, j}] = {j, j};
            }
        }
    }

    p64 get(p64 p) {
        return (e[p].f == -1) ? p: e[p] = get(e[p]); 
    }

    p64 unite(p64 x, p64 y){
        p64 a = get(x), b = get(y);
        if(a == b) return {-1, -1};
        
        // Combine the representative set ranges
        mapp[a].f = min(mapp[a].f, mapp[b].f);
        mapp[a].s = max(mapp[a].s, mapp[b].s);

        // Combine the disjoint sets
        e[b] = a;
        return mapp[a];
    }

};

vp64 dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main(){
    ll n, m; cin >> n >> m;

    DSU dsu(n+3, m+3);
    vv64 mat(n+3, v64(m+3, 1e9));
    priority_queue<v64, vv64, greater<v64>> q;
    for(ll r = 1; r <= n; r++){
        for(ll c = 1; c <= m; c++){
            cin >> mat[r][c];
            q.push({mat[r][c], r, c});
        }
    }

    while(!q.empty()){
        auto tp = q.top(); q.pop();
        ll val = tp[0], r = tp[1], c = tp[2];
        for(auto& [dr, dc]: dirs){
            auto nr = dr+r, nc = dc+c;
            if(mat[nr][nc] <= val){
                p64 ret = dsu.unite({nr, nc}, {r, c});
                if(ret.s - ret.f + 1 == m){
                    cout << val << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}