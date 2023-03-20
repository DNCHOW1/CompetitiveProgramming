#include <bits/stdc++.h>  
 
using namespace std;
 
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
    ll l, d, n; cin >> l >> d >> n;
    // start 6 away from 0 & go 6 from l
    l -= 6;
    set<ll> pos;
    while(n--) {
        ll num; cin >> num;
        pos.insert(num);
    }

    ll tot = 0;
    // precalculate the poles here?
    if(!pos.empty()){
        if(pos.count(6) == 0) tot += ((*pos.begin()-6)/d);
        if(pos.count(l) == 0) tot += ((l-(*(--pos.end())))/d);
    } else{
        tot = ((l-6)/d) + 1;
    }

    ll b = -1;
    // account for the case where birds are present on b and or l
    for(auto p: pos){
        // if(b == 6 && p == l) avail = ((p-b)/d) + 1;
        // else if(b == 6 || p == l) avail = ((p-b)/d);
        // else avail = ((p-b)/d) - 1;
        // tot += avail;
        if(b != -1) tot += ((p-b)/d) - 1;
        b = p;
    }

    // affect count if last isn't bad
    cout << tot << endl;
    return 0;
}