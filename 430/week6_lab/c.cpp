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
// Forgot to account for the edge case with 100000
//  If we're currently holding 100000, don't want to buy any more, even if tot >= days[i]
//  I did cap hold to 100k, but I didn't account for it in the if conditional
// Didn't understand what the problem was asking at all during the contest
// Didn't get the insight with greedy approach at all.
//  should've ruled out dp and tried for a greedy solution immediately

int main(){
    ll d; cin >> d; // days are from OLDEST to NEWEST
    v64 days(d);

    ll hold = 0; // capped at 100k
    ll tot = 100; // use this to determine what she can buy
    ll mx = 100;
    for(ll i = 0; i < d; i++){
        cin >> days[i];
    }

    for(ll i = 0; i < d-1; i++){
        if(tot >= days[i] && hold != 100000LL){
            // remember to cap hold to 100,000
            hold = min(100000LL, tot/days[i]);
            tot -= hold*days[i];
        }
        if(hold > 0 && days[i+1] < days[i]){
            tot += days[i]*hold;
            hold = 0;
        }
        mx = max(tot, mx);
    }

    if(hold > 0){
        mx = max(mx, tot+(hold*days[d-1]));
    }
    cout << mx << endl;
    return 0;
}