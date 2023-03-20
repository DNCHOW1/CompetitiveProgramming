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
    ll n, k; cin >> n >> k;
    v32 a(n); v64 pre(n+5); v32 seen(n+5, -1);
    for(auto &x: a) cin >> x;

    int l = -1; // Keep looping until we find the loop index
    int i = 1;
    ll tot = 0;
    for(; k > 0 ; k--, i++){
        int t = tot%n;
        if(seen[t] != -1){
            pre[i] = tot;
            l = seen[t];
            break;
        }
        seen[t] = i;
        tot += a[t];
        pre[i] = tot;
    }

    if(k > 0){
        ll lenC = i - l; // what if lenC == 0? <<<< not possible
                        // but it could be == 1
        tot += (pre[i]-pre[l-1])*(k/lenC); // could be horribly wrong
        tot += (pre[(k%lenC)+l-1] - pre[l-1]);
    }
    cout << tot << endl;
    // cout << 7390478 - 8784056 << endl;
    // cout << 690081 + 703497 << endl;
    return 0;
}