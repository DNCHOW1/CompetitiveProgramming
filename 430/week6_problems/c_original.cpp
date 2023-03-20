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
ll MOD1 = 1e18 + 7;

// Reflections:
// Thinking a bit too long, shold've recognized that this wouldn't really be brute force.
// Didn't get the insight for 1col or 1row, in this case parities wouldn't matter at all
// When implementing above, forgot to have a check ensuring that all vals consistent

// parity is starting even or odd
// z is row wise or col wise parity
ll greedy(vv64 mat, int parity, int z){
    ll sm = 0;
    for(auto i = 1; i < mat.size(); i++){
        for(auto j = 1; j < mat[0].size(); j++){
            int par;
            if(z == 0){
                if((i-1)%2 == 0) par = parity;
                else par = !parity;
            } else{
                if((j-1)%2 == 0) par = parity;
                else par = !parity;
            }

            if(mat[i][j] == 0){
                // get the minimum possible based off max(prev_h, prev_v)+1 and ceiled to parity
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]) + 1;
                if((mat[i][j]&1) ^ par) mat[i][j]++;
            } else{
                if((mat[i][j]&1) ^ par || mat[i][j] <= mat[i-1][j] || mat[i][j] <= mat[i][j-1]) {
                    return 1e18;
                }
            }
            sm += mat[i][j];
        }
    }
    
    // dbg(mat);
    // dbg(sm);
    return sm;
}

ll greedy_corner(vv64& mat){
    ll sm = 0;
    for(ll i = 1; i < mat.size(); i++){
        for(ll j = 1; j < mat[0].size(); j++){
            if(mat[i][j] == 0) mat[i][j] = max(mat[i-1][j], mat[i][j-1])+1;
            if(mat[i][j] <= mat[i-1][j] || mat[i][j] <= mat[i][j-1]) return 1e18;
            sm += mat[i][j];
        }
    }
    return sm;
}

int main(){
    ll n, m; cin >> n >> m; // up to 2000
    vv64 mat(n+1, v64(m+1));

    // #'s that you choose can be however big as you want
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            ll num; cin >> num;
            mat[i][j] = num;
        }
    }

    ll mn;
    if(n == 1 || m == 1){
        mn = greedy_corner(mat);
    } else {
        mn = min(min(greedy(mat, 0, 0), greedy(mat, 0, 1)), min(greedy(mat, 1, 0), greedy(mat, 1, 1)));
    }
    cout << (mn != 1e18 ? mn : -1) << endl;
    return 0;
}