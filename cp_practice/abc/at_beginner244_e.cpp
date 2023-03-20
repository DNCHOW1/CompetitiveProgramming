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

void madd(ll& a, ll b){
    if((a+=b) >= MOD9) a-=MOD9;
}

int main(){
    int n,m,k,s,t,x; // k is length of the sequence, x is the integer to be repeated even # of times
    cin >> n >> m >> k >> s >> t >> x;
    // create a dp array here
    vector<vp64> dp(n + 1, vp64(k+1, {0, 0}));
    vv32 adj(n + 1);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dp[s][0] = {1, 0}; // even, odd
    for(int i = 0; i < k; i++){
        for(int j = 1; j <= n; j++){
            for(auto &v: adj[j]){
                if(j == x){
                    // dp[v][i+1].f += dp[j][i].s;
                    // dp[v][i+1].s += dp[j][i].f;
                    madd(dp[v][i+1].f, dp[j][i].s);
                    madd(dp[v][i+1].s, dp[j][i].f);
                } else{
                    // dp[v][i+1].f += dp[j][i].f;
                    // dp[v][i+1].s += dp[j][i].s;
                    madd(dp[v][i+1].f, dp[j][i].f);
                    madd(dp[v][i+1].s, dp[j][i].s);
                }
                // cout << v << " " << dp[v][k+1].f << " " << dp[v][k+1].s << endl;
            }
        }
    }
    cout << dp[t][k].f << endl;
    return 0;
}