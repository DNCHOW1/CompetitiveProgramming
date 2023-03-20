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

vv32 adj;
v32 ans;
vector<bool> visited;

// You don't count paths from curr->x then x->curr
// HOWEVER, if some node is visited and you're not an immediate children
// that means there's a cycle and that means theres at least 2 distinct cities

bool dfs(int curr, int par){
    visited[curr] = 1;
    for(auto &x: adj[curr]){
        ans.pb(x);
        if(visited[x] == 0){
            if(dfs(x, curr)) return 1;
        } else if(x != par){
            return 1;
        }
        ans.pop_back();
    }
    return 0;
}

int main(){
    int n, m; cin >> n >> m;
    adj = vv32(n+1, v32());
    visited = vector<bool>(n + 1);
    while(m--){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for(int i = 1; i <= n; i++){
        if(visited[i] == 0){
            ans.pb(i);
            if(dfs(i, 0)){
                // There's a cycle somewhere in this connected component
                bool flag = false;
                for(int i = 0; i < ans.size(); i++){
                    if(ans[i] == ans.back() && !flag){
                        flag = true;
                        cout << ans.size() - i << endl;;
                    }
                    if(flag) cout << ans[i] << " ";
                }
                cout << endl;
                return 0;
            }
            ans.pop_back();
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}