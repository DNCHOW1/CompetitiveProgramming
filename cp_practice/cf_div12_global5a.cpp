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

void solve(int n){
    // happy case even
    // unhappy odd
    ll sum = 0, oc = 0;
    v64 a;
    for(int i = 0; i < n; i++){
        ll temp; cin >> temp;
        sum += floor(temp/2.0);
        oc += (temp % 2);
        a.pb(temp);
    }

    for(auto &x: a){
        if(x % 2 == 0) cout << x / 2 << endl;
        else{
            ll res = floor(x / 2.0); // what if sum initially 0, and you need to alternate between floor and ceil
            if(sum < 0){
                sum++;
                cout << res+1 << endl;
            } else{
                cout << res << endl;
            }
        }
    }
}

int main(){
    int n; cin >> n;
    // cout << -7/2.0 << endl;
    solve(n);
    return 0;
}