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
    int n, x; cin >> n >> x;
    v32 pri(n), pag(n);
    for(auto &num: pri) cin >> num;
    for(auto &num: pag) cin >> num;
    v64 dp(x+1); // keep track of maximum # of pages for a given price; index = price, elem = pages
    // set initial dp state?

    for(int i = 0; i < n; i++){
        for(int j = x; j >= 1; j--){ // iterate through the prices
            if(j - pri[i] < 0) break;
            dp[j] = max(dp[j], dp[j-pri[i]] + pag[i]);
        }
    }
    cout << dp[x] << endl;
    return 0;
}