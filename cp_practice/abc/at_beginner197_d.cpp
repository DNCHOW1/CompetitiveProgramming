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
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    pair<long double, long double> mid = make_pair((a + c)/2.0, (b + d)/2.0);
    pair<long double, long double> vect = make_pair(a - mid.f, b - mid.s);
    long double angle = (2*M_PI)/n;
    pair<long double, long double> res = make_pair(vect.f * cos(angle) - vect.s * sin(angle), vect.f * sin(angle) + vect.s * cos(angle));

    // cout << res.f << " " << res.s << endl;
    printf("%.9Lf %.9Lf\n", mid.f + res.f, mid.s + res.s);
    return 0;
}