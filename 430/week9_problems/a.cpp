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

vp64 dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

ll n, m, tot = 0;

char mat[1005][1005] = {};
bool sea[1005][1005] = {};
vv64 cnt;

void fill_sea(ll r, ll c){
    sea[r][c] = 1;
    for(auto& [dr, dc]: dirs){
        auto nr = r + dr, nc = c + dc;
        if(nr >= 0 && nr < n && nc >= 0 && nc < m && sea[nr][nc] == false){
            if(mat[nr][nc] == '0'){
                fill_sea(nr, nc);
            } else if(mat[nr][nc] == '1') {
                tot++;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    cnt = vv64(n, v64(m, 0));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    for(ll i = 0; i < n; i++){
        if(!sea[i][0] && mat[i][0] == '0')
            fill_sea(i, 0);
        if(!sea[i][m-1] && mat[i][m-1] == '0')
            fill_sea(i, m-1);
        tot += mat[i][0] == '1';
        tot += mat[i][m-1] == '1';
    }
    for(ll j = 0; j < m; j++){
        if(!sea[0][j] && mat[0][j] == '0')
            fill_sea(0, j);
        if(!sea[n-1][j] && mat[n-1][j] == '0')
            fill_sea(n-1, j);
        tot += mat[0][j] == '1';
        tot += mat[n-1][j] == '1';
    }

    cout << tot << endl;
    return 0;
}