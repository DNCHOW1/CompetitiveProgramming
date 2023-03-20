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
    int a, b; cin >> a >> b;
    // cout << (1 << a) << endl;
    long double c = sqrt(pow(a, 2) + pow(b, 2));
    // cout << c << endl;
    // cout << a/c << " " << b/c << endl;
    printf("%.9Lf %.9Lf\n", a/c, b/c);
    return 0;
}