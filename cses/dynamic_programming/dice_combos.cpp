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
    int n; cin >> n;
    v64 ways(n+1);
    ways[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int c = 1; i-c >= 0 && c <= 6; c++){
            ways[i] += ways[i-c];
            ways[i] %= MOD1;
        }
    }
    cout << ways[n] << endl;
    return 0;
}