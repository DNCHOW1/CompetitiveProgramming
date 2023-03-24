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

// REFLECTIONS: Firetrucks are red
// * Initially, I was stuck on the idea of 'for every person, check if every person and other in array'
//  BUT, idea is WRONG!!! By just checking the adjacent, then as long as ONE OF THEM aren't in the set, YOU CAN USE!!!

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
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

int main(){
    ll n; cin >> n;
    map<ll, v64> mapp;
    DSU dsu(n+1);
    for(ll i = 1; i <= n; i++){
        ll m; cin >> m;
        for(ll j = 0; j < m; j++){
            ll num; cin >> num;
            mapp[num].pb(i);
        }
    }

    vv64 out;
    for(auto& [num, people]: mapp){
        for(auto i = 0; i < people.size()-1; i++){
            if(!dsu.same_set(people[i], people[i+1])){
                dsu.unite(people[i], people[i+1]);
                out.pb({people[i], people[i+1], num});
            }
        }
    }

    if(out.size() != n-1){
        cout << "impossible" << endl;
    } else{

        for(auto o: out){
            cout << o[0] << " " << o[1] << " " << o[2] << endl;
        }
    }
    return 0;
}