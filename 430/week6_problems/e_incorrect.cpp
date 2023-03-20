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

// what if you exhaust all letters at point, then another point?
//      what mine does currently is move onto next even though rem = 0

int main(){
    ll n, k; cin >> n >> k;
    priority_queue<p64, vp64, greater<p64>> q;
    for(ll i = 0; i < n; i++){
        ll x, t; cin >> x >> t;
        q.push({x, t});
    }

    ll prev = 0;
    ll rem = k;
    ll tot = 0;
    while(!q.empty()){
        auto [dist, letters] = q.top(); q.pop();

        // refill letters by going back to 0
        if(rem == 0){
            rem = k;
            tot += abs(prev);
            prev = 0;
        }

        tot += abs(dist - prev);
        if(prev < 0 && dist >= 0) rem = k;
        if(rem < letters){
            letters -= rem;

            // continue processing
            ll trips = letters/k;
            letters %= k; // edge case with even division

            tot += 2*abs(dist)*(trips + (letters > 0));

            rem = (letters > 0) ? k - letters: 0;

        } else{
            rem -= letters;
        }
        prev = dist;
    }
    cout << tot+abs(prev) << endl;
    return 0;
}