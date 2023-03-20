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
 
long double dp[101][101][101]{}; // holds the expected operations from this point onwards

long double expected(int i, int j, int k){
    if(i == 100 || j == 100 || k == 100) return 0;
    else if(dp[i][j][k] != 0) return dp[i][j][k];

    long double a = ((expected(i + 1, j, k) + 1)*i) / (i + j + k);
    long double b = ((expected(i, j+1, k) + 1)*j) / (i + j + k);
    long double c = ((expected(i, j, k+1) + 1)*k) / (i + j + k);
    dp[i][j][k] = a + b + c;
    return dp[i][j][k];
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    printf("%.9Lf\n", expected(a, b, c));
    return 0;
}