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
    ll n, k; cin >> n >> k;
    priority_queue<p64, vp64, greater<p64>> neg;
    priority_queue<p64> pos;
    for(ll i = 0; i < n; i++){
        ll x, t; cin >> x >> t;
        if(x < 0) neg.push({x, t});
        else pos.push({x, t});
    }

    ll tot = 0, prev = 0, rem = k;
    while(!neg.empty()){
        auto [dist, letters] = neg.top(); neg.pop();

        if(rem == 0){
            rem = k;
            tot += abs(prev);
            prev = 0;
        }

        tot += abs(dist-prev);
        if(rem < letters){
            letters -= rem;

            // continue processing
            ll trips = letters/k;
            letters %= k; // edge case with even division
            tot += 2*abs(dist)*(trips + (letters > 0));
            rem = (letters > 0) ? k - letters: 0;

        } else rem -= letters;
        prev = dist;
    }

    // 10, 35, 
    rem = k;
    while(!pos.empty()){
        auto [dist, letters] = pos.top(); pos.pop();

        if(rem == 0){
            rem = k;
            tot += abs(prev);
            prev = 0;
        }

        tot += abs(dist-prev);
        if(rem < letters){
            letters -= rem;

            // continue processing
            ll trips = letters/k;
            letters %= k; // edge case with even division
            tot += 2*abs(dist)*(trips + (letters > 0));
            rem = (letters > 0) ? k - letters: 0;
        } else rem -= letters;
        prev = dist;
    }
    cout << tot+abs(prev) << endl;
    return 0;
}