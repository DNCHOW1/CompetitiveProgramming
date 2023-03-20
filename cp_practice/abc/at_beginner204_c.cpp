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

int seen[2003]{};
vv32 adj(2003, v32()); // initialized the inner vector to size 2003, but that would be humongous!!!

ll dfs(const int s, int i){
    ll cnt = 0;
    if(seen[i] == s) return cnt;
    seen[i] = s;
    for(auto v: adj[i]){
        if(v != 0) cnt += dfs(s, v);
    }
    return 1 + cnt;
}

int main(){
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
    }

    ll total = 0;
    for(int i = 1; i <= n; i++){
        total += dfs(i, i);
    }
    cout << total << endl;
    return 0;
}