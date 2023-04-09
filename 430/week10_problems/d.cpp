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

int main(){
    ll n, m, p; cin >> n >> m >> p;
    set<ll> insec;
    for(ll i = 0; i < p; i++) {
        ll num; cin >> num;
        insec.insert(num);
    }

    priority_queue<v64, vv64, greater<v64>> qsec;
    priority_queue<v64, vv64, greater<v64>> qinsec;
    while(m--){
        ll a, b, l; cin >> a >> b >> l;
        if(insec.count(a) == 1 || insec.count(b) == 1){
            qinsec.push({l, a, b});
        } else{
            qsec.push({l, a, b});
        }
    }

    if(p != n){
        DSU dsu(n+1);
        bool flag = 0;
        while(!qsec.empty()){
            auto tp = qsec.top(); qsec.pop();
            if(dsu.unite(tp[0], tp[1])){

            }
        }
    } else{
        // ensure that we have a complete graph
    }
    return 0;
}