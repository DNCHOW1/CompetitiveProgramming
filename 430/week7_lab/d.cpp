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



int main(){
    ll s0, s1, r0, r1;
    while(cin >> s0 >> s1 >> r0 >> r1){
        if(s0 == 0 || s1 == 0 || r0 == 0 || r1 == 0) {
            break;
        }

        if(s0 < s1) swap(s1, s0);
        if(r0 < r1) swap(r1, r0);

        if(s0 == 2 && s1 == 1) s0 *= 1000;
        else if(s0 == s1) s0 *= 100;
        if(r0 == 2 && r1 == 1) r0 *= 1000;
        else if(r0 == r1) r0 *= 100;

        if(s0*10 + s1 > r0*10 + r1){
            cout << "Player 1 wins." << endl;
        } else if(s0*10 + s1 < r0*10 + r1){
            cout << "Player 2 wins." << endl;

        } else{
            cout << "Tie." << endl;
        }
    }
    return 0;
}