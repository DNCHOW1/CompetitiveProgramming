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

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

int main(){
    int n, m; cin >> n >> m;
    vector<pair<int, pair<int, int>>> ab;
    DSU dsu(n+1);
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        ab.pb({c, {a, b}});
    }
    sort(ab.begin(), ab.end());

    ll tot = 0;
    for(int i = 0; i < ab.size(); i++){
        auto& x = ab[i];
        auto& conn = x.s;
        if(x.f <= 0){
            dsu.unite(conn.f, conn.s);
        } else{
            if(dsu.same_set(conn.f, conn.s)){
                tot += x.f;
            } else{
                dsu.unite(conn.f, conn.s);
            }
        }
    }
    cout << tot << endl;
    return 0;
}