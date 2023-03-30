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
// Correctly identified that relevant cases occur when a smaller transitions to bigger
//  HOWEVER!!! Didn't account for case where "more" on the same level moves to upper level. Need to think more
// Would've been faster to implement if I just checked how much are better in curr level, then update with better in next level
//  ** see code below with the two for loops

int main(){
    ll n, m; cin >> n >> m;

    map<ll, set<p64>> solved;
    map<ll, p64> info;
    ll rank = 1, more = 0; // 1's current rank, how many are more in current problem level
    for(ll i = 1; i <= n; i++) {
        solved[0].insert({0, -i});
        info[i] = {0, 0}; // solved 0 problems, current penalty is 0
    }

    vector<ll> out;
    while(m--){
        ll t, p; cin >> t >> p;

        if(t != 1){
            p64 currt = {info[t].f, -info[t].s}, curr1 = {info[1].f, -info[1].s};
            p64 newt = {info[t].f+1, -info[t].s-p};
            if(currt <= curr1 && newt > curr1){
                rank++;
                more += (info[t].f+1 == info[1].f && info[t].s+p < info[1].s);
                more -= (info[t].f == info[1].f && info[t].s < info[1].s);
            } else if(currt > curr1){
                more -= (info[t].f == info[1].f && info[t].s < info[1].s);
            }
        } else{
            rank -= more;
            // for(auto& [pen, team]: solved[info[t].f]){
            //     if(info[t].s > pen) rank--;
            //     else break;
            // }
            rank -= solved[info[t].f+1].size();
            more = 0;
            for(auto& [pen, team]: solved[info[t].f+1]){
                if(info[t].s+p > pen) more++;
                else break;
            }
            rank += more;
        }
        solved[info[t].f].erase({info[t].s, -t});
        info[t].f++;
        info[t].s += p;
        solved[info[t].f].insert({info[t].s, -t});
        out.pb(rank);
    }

    for(auto num: out) cout << num << endl;
    return 0;
}