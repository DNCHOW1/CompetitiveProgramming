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
#define INF 1e18
ll MOD9 = 998244353;
ll MOD1 = 1e9 + 7;
 
ll func(ll a, ll b){
    return a*a*a + a*a*b + b*b*a + b*b*b;
}

int main(){
    ll n; cin >> n;

    ll x = INF;
    for(ll a = 0; a <= 1e6; a++){
        ll l = 0, r = 1e6;
        while(l < r){ // we want to find the lowest # that is greater than n
            ll mid = (r-l)/2 + l;
            if(func(a, mid) >= n){
                r = mid;
            } else{
                l = mid + 1;
            }
        }
        // cout << a << " " << l << endl;
        x = min(x, func(a, l));
    }
    cout << x << endl;
    return 0;
}