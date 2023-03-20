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
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define f first
#define s second
#define INF 2e18
ll MOD9 = 998244353;
ll MOD1 = 1e9 + 7;
 
ll modpow(ll a, ll b, ll m){
    if(b == 0) return 1ll; // %MOD9?
    ll u = modpow(a, b/2ll, m);
    u = (u*u)%m;
    if(b%2ll == 1ll) u = (u*a)%m;
    return u;
}

int main(){
    ll n, k, m; cin >> n >> k >> m;
    // k ^ (n*m)
    // Using modular exponentiation, (x^n)modm can be done in O(logn)
    // thus, this should be done in log(n*m) ~ 36
    // cout << modpow(m, modpow(k, n, MOD9-1), MOD9) << endl;
    if(m % MOD9 == 0){
        cout << 0 << endl;
    } else{
        ll kn = modpow(k%(MOD9-1), n, MOD9-1);
        cout << modpow(m%MOD9, kn, MOD9) << endl;
    }
    return 0;
}