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
// Break the test case with the first element out, that way the code is easier to deal with
// Stop being so dumb and get more sleep

int main(){
    // calc for each policy
    // leave up
    // leave down
    // leave how you found it
    // calculate cost

    // first char is the initial position

    // UUUDDUDU
    // _0024466
    // _1333557
    // _

    // DUDUDU
    // _13355
    // _22446
    // _12345

    // UUUU
    // DDDD
    // UDDD
    // DUUU

    ll u = 0, d = 0, f = 0;
    string in; cin >> in;
    char up = in[0];
    char down = in[0];
    char special = in[0];
    for(int i = 1; i < in.size(); i++){
        if(in[i] == 'U'){
            u += (up == 'U') ? 0: 1; // up policy -> good / up
            d += (down == 'U') ? 1: 2; // down policy -> do business then down / up, business, down
            f += (special == 'U') ? 0: 1; // 
        } else{
            u += (up == 'D') ? 1: 2; // up policy -> do business then up / down business up
            d += (down == 'D') ? 0: 1; // down policy -> good / down
            f += (special == 'D') ? 0: 1; // left policy
        }
        up = 'U';
        down = 'D';
        special = in[i];
    }
    cout << u << endl;
    cout << d << endl;
    cout << f << endl;
    return 0;
}