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
 

int main(){
    ll x, k ,d;
    cin >> x >> k >> d;
    ll amt = abs(x)/d, curr = x%d;
 
    if(amt >= k){ // not enough moves to get close to 0
        cout << min(abs(x + k*d), abs(x - k*d)) << endl;
    } else{
        k -= amt;
        if(k % 2){ // k is odd
            cout << min(abs(curr + d), abs(curr - d)) << endl;
        } else{
            cout << abs(curr) << endl;
        }
    }
    return 0;
}