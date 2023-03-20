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

void solve(){
    ll l, n; cin >> l >> n;
    v64 arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll mn = 0, mx = max(arr[0], l-arr[n-1]);

    sort(arr.begin(), arr.end());

    for(ll i = 0; i < n; i++){
        if(i != 0){
            auto mid = arr[i]-arr[i-1];
            mx = max(mx, mid+l-arr[i]);
        }
        if(i != n-1){
            auto mid = arr[i+1]-arr[i];
            mx = max(mx, mid+arr[i]);
        }
        mn = max(mn, min(arr[i], l-arr[i]));
    }

    cout << mn << " " << mx << endl;
}

int main(){
    ll n; cin >> n;
    while(n--){
        solve();
    }
    return 0;
}