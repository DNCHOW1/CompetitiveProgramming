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

const int mx = 1e5 + 3;
// int color[mx][mx]{}; // Initialize to 0, so coloring will be as follows: 1 - white, 2 - black
int color[mx]{};
vector<vp32> adj;
 
// define dfs func here??
void dfs(int u, int c){
    color[u] = c;
    for(auto& [v, w]: adj[u]){
        if(color[v] == 0){
            if(w%2 == 0){ // even same color
                dfs(v, c);
            } else{
                dfs(v, (c == 1) ? 2: 1);
            }
        }
    }
}

int main(){
    int n; cin >> n;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }

    adj = vector<vp32>(n+1, vp32());
    for(int i = 0; i < n-1; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            dfs(i, 1);
        }
    }

    for(int i = 1; i <= n; i++){
        cout << (color[i]-1) << endl;
    }
    return 0;
}