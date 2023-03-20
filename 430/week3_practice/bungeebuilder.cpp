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
    // to connect two mountains, everything in middle must be <
    // n^2 or nlogn

    ll n; cin >> n; // [1, 1e6]
    v64 arr(n);
    for(ll i = 0; i < n; i++) cin >> arr[i];
    // just use two pointers

    ll l = 0, r = n-1;
    ll mxL = arr[l], mxR = arr[r];
    ll mx = 0;
    while(l <= r){
        if(mxL <= mxR){
            mxL = max(mxL, arr[l]);
            mx = max(mx, min(mxL, mxR) - arr[l]);
            l++;
        } else{
            mxR = max(mxR, arr[r]);
            mx = max(mx, min(mxL, mxR) - arr[r]);
            r--;
        }
    }
    cout << mx << endl;
    return 0;
}