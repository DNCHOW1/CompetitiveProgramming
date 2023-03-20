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

vp64 asc(5005);
vp64 desc(5005);
ll tot = 0;

double calc(ll n, double tme){
    double pos = 0;
    for(ll i = 0; i < n; i++){
        if(tme > asc[i].s) {
            tme -= asc[i].s;
            pos += asc[i].f;
        } else{
            pos += tme*asc[i].f/asc[i].s;
            break;
        }
    }
    return pos;
}

double calc2(ll n, double tme){
    double pos = tot;
    for(ll i = 0; i < n; i++){
        if(tme > desc[i].s) {
            tme -= desc[i].s;
            pos -= desc[i].f;
        } else{
            pos -= tme*desc[i].f/desc[i].s;
            break;
        }
    }
    return pos;
}

int main(){
    ll a, d; cin >> a >> d;
    double at = 0, dt = 0;
    for(ll i = 0; i < a; i++) {
        cin >> asc[i].f >> asc[i].s;
        at += asc[i].s;
        tot += asc[i].f;
    }
    for(ll i = 0; i < d; i++) {
        cin >> desc[i].f >> desc[i].s;
        dt += desc[i].s;
    }

    double mn = 0, mx = min(at, dt);
    while(mx - mn >= 1e-5){
        double offset = (mx-mn)/3;
        double fst = mn + offset, snd = mn + offset*2;
        if(abs(calc(a, fst) - calc2(d, fst)) <= abs(calc(a, snd) - calc2(d, snd))){
            mx = snd;
        } else mn = fst;
    }
    cout << setprecision(8) << mn << endl;
    return 0;
}