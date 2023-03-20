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

ll LOG = log2(300000) + 1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    vv32 up(n + 1, v32(LOG));
    v32 depth(n+1);
    v32 val(n+1);

    auto dpUp = [&](int num){
        for(int j = 1; j <= LOG; j++){
            up[num][j] = up[up[num][j-1]][j-1];
        }
    };

    auto kthA = [&](int a, int k){ // find the kth ancestor from a
        for(int j = 0; j <= LOG; j++){
            if(k & (1 << j)){
                a = up[a][j];
            }
        }
        return a;
    };

    auto lca = [&](int a, int b){
        if(depth[a] < depth[b]) swap(a, b); // this way a will always have greater depth
        int diff = depth[a] - depth[b];
        a = kthA(a, diff);
        if(val[a] == val[b]) return a;

        // Now that a & b are at the same depth, binary search their LCA by finding last point where != is true
        for(int i = LOG; i >= 0; i--){
            if(val[up[a][i]] != val[up[b][i]]){
                a = up[a][i];
                b = up[b][i];
            }
        }
        return up[a][0];
    };

    for(int i = 1; i <= n; i++){
        char op;
        int v, w;
        cin >> op >> v;
        if(op == 'a'){
            val[i] = i;
            up[i][0] = v;
            depth[i] = depth[v] + 1;
        } else if(op == 'b'){ // deal w/ the edge case where at elem "stack" is empty
            cout << val[v] << endl;
            val[i] = val[up[v][0]];
            up[i][0] = up[up[v][0]][0];
            depth[i] = depth[up[v][0]];
        } else{
            cin >> w;
            val[i] = val[v];
            up[i][0] = up[v][0];
            depth[i] = depth[v];
            cout << depth[lca(v, w)] << endl;
        }
        dpUp(i);

    }
    return 0;
}