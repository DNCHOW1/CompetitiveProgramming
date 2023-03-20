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
    DSU dsu(n + 1);
    while(m--){
        int u, v; cin >> u >> v;
        dsu.unite(u, v);
    }
    priority_queue<int, v32, greater<int>> q1;
    for(int i = 0; i < n + 1; i++) {
        if(dsu.e[i] < 0){
            cout << dsu.e[i] << endl;
            q1.push(-dsu.e[i]);
        }
    }

    int k; cin >> k;
    priority_queue<int, v32, greater<int>> q2;
    while(k--) {
        int l, r; cin >> l >> r;
        q2.push(r-l+1);
    }

    if(q2.size() > q1.size()){
        cout << "NO" << endl;
    } else{
        while(!q1.empty()){
            if(q2.empty()){
                cout << "NO" << endl;
                return 0;
            } else if(q1.top() > q2.top()){
                q2.pop();
            } else{
                q1.pop();
                q2.pop();
            }
        }
        cout << "YES" << endl;
    }
    return 0;
}