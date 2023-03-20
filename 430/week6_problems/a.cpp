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

// 3,5 4,6 5,7
// 3,100 4,7 20,30

int main(){
    ll n; cin >> n;
    // multiset<p64> temps;
    vp64 temps;
    for(ll i = 0; i < n; i++){
        ll l, u; cin >> l >> u;
        // temps.insert({l, u});
        temps.pb({l, u});
    }

    sort(temps.begin(), temps.end());

    ll cnt = 0;
    ll prev = -1e9;
    for(auto& [l, u]: temps){
        if(prev < l){
            cnt++;
            prev = u;
        }
        prev = min(prev, u);
    }

    // priority_queue<p64, vp64, greater<p64>> temps;
    // for(ll i = 0; i < n; i++){
    //     ll l, u; cin >> l >> u;
    //     temps.push({l, u});
    // }

    // ll cnt = 0;
    // p64 curr = {-1e9, -1e9};
    // while(!temps.empty()){
    //     auto tp = temps.top(); temps.pop();
    //     // dbg(tp);
    //     // dbg(curr);
    //     if(tp.f > curr.s){
    //         cnt++;
    //         curr = tp;
    //     } else{
    //         curr.f = max(curr.f, tp.f);
    //         curr.s = min(curr.s, tp.s);
    //     }
    // }

    cout << cnt << endl;
    return 0;
}