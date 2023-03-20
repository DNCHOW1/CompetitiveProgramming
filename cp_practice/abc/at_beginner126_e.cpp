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
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define f first
#define s second
#define INF 2e18
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
    int n, m;
    cin >> n >> m;
    vector<bool> visited(n+1);
    DSU dsu(n+1);
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        dsu.unite(x, y);

        // // In both cases below, if you reveal one you reveal the other
        // if(z%2){ // parities of x and y !=

        // } else{ // parities of x and y the same, but they can both be odd or even

        // }

    }

    int magic = 0;
    for(int i = 1; i <= n; i++){
        int index = dsu.get(i);
        if(visited[index] == false){
            visited[index] = true;
            magic++;
        }
        // cout << dsu.get(i) << endl;
    }

    cout << magic << endl;
    return 0;
}