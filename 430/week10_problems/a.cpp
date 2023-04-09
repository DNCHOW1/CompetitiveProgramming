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

// Create a DSU for Kruskal's Alg, then continue until # all components == s
struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

void solve() {
    ll S, p; cin >> S >> p;
    vp64 posts(p);
    for(ll i = 0; i < p; i++){
        ll x, y; cin >> x >> y;
        posts[i] = {x, y};
    }

    // {1, 2, 3}
    priority_queue<vector<double>, vector<vector<double>>, greater<vector<double>>> q;
    DSU dsu(p+1);
    ll components = p;
    for(double i = 0; i < p; i++){
        for(double j = i + 1; j < p; j++){
            q.push({
                sqrt(pow(posts[j].s-posts[i].s, 2) + pow(posts[j].f-posts[i].f, 2)),
                i,
                j
            });
        }
    }

    double mn = 0;
    while(components != S){
        auto fr = q.top(); q.pop();
        mn = fr[0];
        if(dsu.unite(fr[1], fr[2])) components--;
    }
    cout << fixed << setprecision(2) << mn << endl;
}

int main(){
    ll n; cin >> n;
    while(n--){
        solve();
    }
    return 0;
}