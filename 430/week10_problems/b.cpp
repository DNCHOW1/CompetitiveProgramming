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

// Reflections:
//  My initial understanding of the bridges algorithm was flawed
//  Didn't account for the case where the graph wouldn't be fully connected. Bad assumption on my part

// Idea - if there exists a bridge, then output true; else false
// low value is...
//  own value
//  ANY back edge
//  lowest returned from recursive call on children, NOT INCLUDING PARENT

bool bridge = false;
ll cnt = 0;

// need to keep track of parent
ll dfs(vv64& adj, map<ll, p64>& visited, ll u, ll p = -1){
    ll d = cnt++;
    visited[u] = {d, d};
    for(auto v: adj[u]){
        // if vertex not visited, run dfs and retrieve low
        // else get the neighbor's low (backedge)
        if(v == p) continue;
        if(visited.count(v) == 1) visited[u].s = min(visited[u].s, visited[v].f); // back edges
        else{
            bridge |= (dfs(adj, visited, v, u) > d);
            visited[u].s = min(visited[u].s, visited[v].s);
        }
    }
    return visited[u].s;
}

int main(){
    ll p, c; // # of people James wants to invite, c lines
    while(cin >> p >> c){
        if(p == 0 && c == 0) break;

        vv64 adj(p+1);
        cnt = 0;
        bridge = false;
        map<ll, p64> visited;
        while(c--){
            ll u, v; cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        // call dfs function
        dfs(adj, visited, 0, -1);
        cout << (bridge || cnt != p ? "Yes": "No") << endl;

    }
    return 0;
}