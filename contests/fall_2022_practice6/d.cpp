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

// array is non-negative
// use a ll

// b - step function, zero out all 
// s - stay within (n-1) [0, k-1] + [k*b, k*(b+1)-1] 

int main(){
    int t; cin >> t;
    while(t--){
        ll n, k, b, s;
        cin >> n >> k >> b >> s; // sum of all n over all test cases <= 1e5 -- O(n) solution

        if(s < k*b || s > (n-1)*(k-1)+k*(b+1)-1) cout << -1;
        else{
            cout << min(s, k*(b+1)-1) << " ";
            s -= min(s, k*(b+1)-1);
            for(ll i = 0; i < n-1; i++){ // We're not counting the big step func
                cout << min(s, k-1) << " ";
                s -= min(s, k-1);
            }
        }
        cout << endl;
    }
    return 0;
}