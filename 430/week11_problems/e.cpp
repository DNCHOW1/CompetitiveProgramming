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

stack<ll> S;
ll mat[55][55] = {};
ll timer = 0;
ll components = 0;

ll dfs(ll v, v64& visited, v64& tims, v64& low){
    visited[v] = 0; // exploring
    tims[v] = low[v] = ++timer;
    S.push(v);

    for(ll i = 0; i < 55; i++){
        if(mat[v][i]){
            if(visited[i] == -1) low[v] = min(low[v], dfs(i, visited, tims, low)); // descendant propogation
            else if(visited[i] == 0) low[v] = min(low[v], tims[i]); // back edge to exploring
        }
    }
    if(tims[v] == low[v]){
        // pop stack until you get to v
        ll temp = -1;
        while(temp != v){
            temp = S.top(); S.pop();
            visited[temp] = 1; // finished visiting
        }
        components++;
    }
    return low[v];
}

void helper(ll n){
    timer = components = 0;
    v64 visited(55, -1); // reset visited
    v64 tims(55, -1); // reset tims
    v64 low(55, -1); // reset low
    for(ll i = 0; i < n; i++){
        if(visited[i] == -1) {
            dfs(i, visited, tims, low);
        }
    }
}

int main(){
    ll n, m;
    ll cs = 1;
    while(cin >> n){
        if(cin.eof()) break;
        cin >> m;

        // Reset mat
        for(ll i = 0; i < 55; i++){
            for(ll j = 0; j < 55; j++)
                mat[i][j] = 0;
        }

        // Fill in mat
        map<p64, ll> mapping;
        for(ll i = 0; i < m; i++){
            ll a, b; cin >> a >> b;
            mat[a][b] = 1;
            mapping[{a, b}] = i;
        }

        helper(n);

        printf("Case %lld: ", cs);
        if(components == 1) cout << "valid" << endl;
        else{
            bool flag = 0;
            v64 mn(3, 1e9);
            for(ll i = 0; i < n; i++){
                for(ll j = 0; j < n; j++){
                    if(mat[i][j]){
                        mat[i][j] = 0;
                        mat[j][i] = 1;
                        helper(n);
                        mat[i][j] = 1;
                        mat[j][i] = 0;
                        if(components == 1){
                            mn = min(mn, {mapping[{i, j}], i, j});
                            flag = 1;
                        }
                    }
                }
            }

            if(flag) cout << mn[1] << " " << mn[2] << endl;
            else cout << "invalid" << endl;
        }
        cs++;
    }
    return 0;
}