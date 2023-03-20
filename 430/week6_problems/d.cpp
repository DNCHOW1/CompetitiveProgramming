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

vector<string> mat;
v32 ships;
int hits = 0;
set<p32> locs;

// Check to see if a ship can be placed at the square
bool check(int i, int j, int l, int d){
    if(d == 0){ // horz
        if(j+l > mat.size()) return false;
        for(int index = j; index < j + l; index++)
            if(mat[i][index] == 'X' || locs.count({i, index}) == 1) return false;
    } else{ // vert
        if(i+l > mat.size()) return false;
        for(int index = i; index < i + l; index++)
            if(mat[index][j] == 'X' || locs.count({index, j}) == 1) return false;
    }
    return true;
}

ll dfs(int ship){
    if(ship >= ships.size()) return (hits == 0);

    ll cnt = 0;
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat.size(); j++){
            // place horizontally
            if(check(i, j, ships[ship], 0)){
                for(int index = j; index < j + ships[ship]; index++){
                    locs.insert({i, index});
                    hits -= mat[i][index] == 'O';
                }
                cnt += dfs(ship+1);
                for(int index = j; index < j + ships[ship]; index++){
                    locs.erase({i, index});
                    hits += mat[i][index] == 'O';
                }
            }

            // place vertically
            if(check(i, j, ships[ship], 1) && ships[ship] != 1){
                for(int index = i; index < i + ships[ship]; index++){
                    locs.insert({index, j});
                    hits -= mat[index][j] == 'O';
                }
                cnt += dfs(ship+1);
                for(int index = i; index < i + ships[ship]; index++){
                    locs.erase({index, j});
                    hits += mat[index][j] == 'O';
                }
            }
        }
    }

    return cnt;
}

int main(){
    int n, k; cin >> n >> k;
    mat = vector<string>(n);
    ships = v32(k);
    for(int i = 0; i < n; i++) cin >> mat[i];
    for(int i = 0; i < k; i++) cin >> ships[i];

    for(auto& str: mat){
        for(auto& c: str){
            hits += (c == 'O');
        }
    }

    cout << dfs(0) << endl;

    // with ships, start at first ship placed horz at index 0, 0
    // then on next ship start at index 0, 0 and ensure placement is consistent
    // continue... when done, backtrack to previous ship and place it vertically instead
    return 0;
}