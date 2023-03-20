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
    long double n, k;
    cin >> n >> k;

    long double csum = 0;
    for(int i = 1; i <= n; i++){
        if(i >= k){
            csum += 1;
        } else{
            int power = ceil(log2(k) - log2(i));
            csum += pow(1.0/2, power);
        }
            
    }

    long double res = csum / n;
    printf("%.9Lf\n", res);
    return 0;
}