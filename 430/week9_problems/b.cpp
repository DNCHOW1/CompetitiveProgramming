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

map<string, set<string>> adj; // edges between these nodes should be colored differently
map<string, int> colored; // -1 if uninitialized
bool flag = 0;

void dfs(string in, int color){
    colored[in] = color;
    for(auto& e: adj[in]){
        if(colored[e] == -1)
            dfs(e, !color);
        else if(colored[e] != !color) 
            flag = 1;
    }
}

int main(){
    ll n, m;
    cin >> n;
    while(n--){
        string in; cin >> in;
        colored[in] = -1;
    }

    cin >> m;
    while(m--){
        string a, b; cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    for(auto& [item, coloring]: colored){
        if(coloring == -1){
            dfs(item, 0);
        }
    }

    if(flag){
        cout << "impossible" << endl;
    } else{
        vector<string> one, two;
        for(auto& [item, coloring]: colored){
            if(coloring == 0) one.pb(item);
            else two.pb(item);
        }
        for(auto& item: one) cout << item << " ";
        cout << endl;
        for(auto& item: two) cout << item << " ";
        cout << endl;

    }
    return 0;
}