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
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    ll tot = 0;
    tot += min(a, k); k = max(k-a, 0);
    if(k > 0) k = max(k - b, 0);
    if(k > 0){
        tot -= min(c, k);
    }
    cout << tot << endl;
    return 0;
}