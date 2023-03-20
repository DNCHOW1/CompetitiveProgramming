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

vector<char> arr;
v64 charToLL(26, 1e18);
vv64 nums(26, v64(26));
vector<vector<char>> chars(26, vector<char>(26, '*'));
string in;
vector<vector<v64>> memo(205, vector<v64>(205));

// Reflections:
// **MISSED KEY INSIGHT WHERE THIS WAS 3D DP
//  This is because we want the optimal way to get to some character given [l, r]
//  This also allows us to get multiple optimal ways for some partition [l, r]
// **Made naive assumption that can just shrink l and r by one and combine with partition
//  This is wrong because we also want to see partition left combine with partition right
//  Because there are multiple optimal ways, we also want TO COMPARE COMBINATIONS from left partition and right partition
// **Used bad datastructure at first, map<p64, map<char, ll>> is pretty slow
//  even though passing by reference, having them globally prob better
// Had issues with ties

// map<p64, map<char, ll>> // memo stores range l, r -> map<char, ll>
// above too slow, try vector<vector<v64>(in.size())>(in.size())
// can actually just always have size < 205
void solve(ll l, ll r){
    if(memo[l][r].size()){ // Already been calculated
        return;
    }
    if(l == r) {
        memo[l][r] = v64(26, 1e18);
        memo[l][r][in[l]-'a'] = 0;
        return;
    }

    for(int i = 0; i < 26; i++){
        memo[l][r].pb(1e18);
    }
    for(ll i = l; i < r; i++){
        solve(l, i);
        solve(i+1, r);
        for(int c1 = 0; c1 < 26; c1++){
            for(int c2 = 0; c2 < 26; c2++){
                ll row = charToLL[c1];
                ll col = charToLL[c2];
                if(row == 1e18 || col == 1e18) continue;
                ll newTime = memo[l][i][c1]+memo[i+1][r][c2]+nums[row][col];
                memo[l][r][chars[row][col]-'a'] = min(memo[l][r][chars[row][col]-'a'], newTime);
            }
        }
    }
}

int main(){
    ll k; cin >> k;
    arr = vector<char>(k);
    for(ll i = 0; i < k; i++) {
        cin >> arr[i];
        charToLL[arr[i]-'a'] = i;
    }

    for(ll i = 0; i < k; i++){
        for(ll j = 0; j < k; j++){
            char mid;
            cin >> nums[i][j] >> mid >> chars[i][j];
        }
    }

    ll n; cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> in;
        for(int a = 0; a < 205; a++){
            for(int b = 0; b < 205; b++) memo[a][b].clear();
        }
        pair<ll, char> ans = {1e18, '*'};
        solve(0, in.size()-1);

        for(int c = 0; c < 26; c++){
            if(memo[0][in.size()-1][c] < ans.f){
                ans = {memo[0][in.size()-1][c], c+'a'};
            }
            else if(memo[0][in.size()-1][c] == ans.f && charToLL[c] < charToLL[ans.s-'a']){
                ans = {memo[0][in.size()-1][c], c+'a'};
            }
        }

        cout << ans.f << "-" << ans.s << endl;
    }

    cin >> n;
    return 0;
}