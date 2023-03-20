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

// Reflection:
// Do one more pass to make this more elegant, this would've sped up development time massively
// Keyser's method works because we have the resulting vector from a "naive" solution is what
//      player is associated with that character index
// BUT, what we want to answer is what character associated with a player index
// Essentially, we succesfully calculate the bottom mapping, but we want **THE TOP MAPPING**

int main(){
    ll n, k; cin >> n >> k;
    multiset<p64> legs;
    v64 chars(n);
    map<ll, ll> chars2;
    
    for(int i = 0; i < n; i++) {
        chars[i] = i;
        chars2[i] = i;
    }
    while(k--){
        ll a, b; cin >> a >> b;
        legs.insert({b, a});
    }
    
    for(auto& [temp, ind]: legs){
        auto trueind1 = chars2[ind];
        auto trueind2 = chars2[ind+1];
        swap(chars[trueind1], chars[trueind2]);
        swap(chars2[ind], chars2[ind+1]);
        
    }

    for(int i = 0; i < n; i++) cout << chars[i] << " ";
    cout << endl;
    return 0;
}