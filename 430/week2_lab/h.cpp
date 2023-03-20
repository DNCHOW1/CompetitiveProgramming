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
    int curr, t, n;
    cin >> curr >> t >> n;
    v32 ds(n+1); // from one bus to another
    v32 bs(n); // time to ride this bus
    v32 cs(n); // the intervals this bus arrives
    for(int i = 0; i < n + 1; i++) cin >> ds[i];
    for(int i = 0; i < n; i++) cin >> bs[i];
    for(int i = 0; i < n; i++) cin >> cs[i];

    for(int i = 0; i < n; i++){
        curr += ds[i];
        if(curr%cs[i] != 0) curr += (cs[i] - (curr%cs[i]));
        curr += bs[i];
    }
    cout << ((curr + ds.back() <= t) ? "yes" : "no") << endl;
    return 0;
}