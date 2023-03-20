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

int a[300005];

bool check(int n, ll days, int target){
    ll o = days/2 + days%2, e = days/2; // fine to have extras
    for(int i = 0; i < n; i++){
        ll dist = target - a[i];
        if(dist % 2 == 1) {
            o--;
            dist--;
        }
        if(e > 0){
            e -= (dist/2);
        } else if(o > 0){
            o -= dist;
        } else{
            return false;
        }
    }
    return e >= 0 && o >= 0;
}

void solve(){
    int n; cin >> n;
    int mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    } 

    // binary search the amount of days to get all equal tree height
    ll l = 0, r = 1e15;
    ll ans = -1;
    while(l <= r){
        ll mid = (r-l)/2 + l;
        if(check(n, mid, mx)){
            r = mid - 1;
            ans = mid;
        } else{
            l = mid + 1;
        }
    }
    cout << ans << endl;
}  

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}