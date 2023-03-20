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
    ll n, m, p; cin >> n >> m >> p;
    // # num judges, tar repos, feather storehouses

    // minimize distance between judges and tar and feather, 
    vp64 judges(n);
    vp64 tars(m);
    vp64 feathers(p);
    // maybe instead keep a set of tuples? {index, x, y}
    for(int i = 0; i < n; i++){
        ll x, y; cin >> x >> y;
        // location of the judges
        judges[i] = {x, y};
    }
    for(int i = 0; i < m; i++){
        ll x, y; cin >> x >> y;
        tars[i] = {x, y};
    }
    for(int i = 0; i < m; i++){
        ll x, y; cin >> x >> y;
        feathers[i] = {x, y};
    }

    // assign repos to each judge
    // then asign feathers to each judge
    // if tied, assign to lowest number judge -> if further tie, lowest repo / feather
    return 0;
}