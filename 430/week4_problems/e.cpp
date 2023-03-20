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

// directions
vp64 dirs = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

vector<string> mat;
ll n, m;

bool inMat(ll r, ll c){
    return r >= 0 && r < n && c >= 0 && c < m && mat[r][c] == '#';
}

void dfs(ll r, ll c){
    mat[r][c] = '.';
    for(auto& [dr, dc]: dirs){
        if(inMat(r+dr, c+dc)) dfs(r+dr, c+dc);
    }
}

int main(){
    cin >> n >> m;
    mat = vector<string>(n);
    for(ll i = 0; i < n; i++) cin >> mat[i];

    ll cnt = 0;
    for(ll r = 0; r < n; r++){
        for(ll c = 0; c < m; c++){
            if(mat[r][c] == '#') {
                cnt++;
                dfs(r, c);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}