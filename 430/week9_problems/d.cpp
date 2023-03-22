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


// top sort problem?
int main(){
    ll n, m; cin >> n >> m;
    vv64 adj(n+1);
    v64 indegrees(n+1);
    for(ll i = 0; i < m; i++){
        ll a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        indegrees[b]++;
    }

    queue<ll> q;
    v64 out;
    for(ll i = 1; i <= n; i++){
        if(indegrees[i] == 0) {
            q.push(i);
            out.pb(i);
        }
    }
    while(!q.empty()){
        auto fr = q.front(); q.pop();
        for(auto e: adj[fr]){
            indegrees[e]--;
            if(indegrees[e] == 0) {
                out.pb(e);
                q.push(e);
            }
        }
    }

    if(out.size() != n) cout << "IMPOSSIBLE" << endl;
    else{
        for(auto num: out) cout << num << endl;
    }
    return 0;
}