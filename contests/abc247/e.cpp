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

int x, y;

ll calc(v32& a){
    ll ans = 0;
    int l = 0, r = 0, xc = 0, yc = 0, n = a.size();
    while(l < n){
        if(r < n && (a[r] == x || a[r] == y)){
            xc += (a[r] == x);
            yc += (a[r] == y);
        }
        while(l < n && xc >= 1 && yc >= 1){
            ans += (n - r);
            xc -= (a[l] == x);
            yc -= (a[l] == y);
            l++;
        }

        if(xc < 1 || yc < 1) { // increment r
            if(r == n) break;
            else r++;
        }
    }
    return ans;
}

int main(){
    int n; cin >> n >> x >> y;
    v32 a(n);
    for(auto &aa: a) cin >> aa;

    int i = 0;
    ll ans = 0;
    while(i < n){
        v32 b;
        while(i < n && a[i] >= y && a[i] <= x) {
            b.pb(a[i]);
            i++;
        }
        if(!b.empty()){
            ans += calc(b);
        } else{
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}