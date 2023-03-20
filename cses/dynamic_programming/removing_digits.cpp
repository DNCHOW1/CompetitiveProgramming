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

int maxDig(int num){
    if(num == 0) return 0;
    return max(num%10, maxDig(num/10));
}

int main(){
    int n; cin >> n;
    v64 ways(1e6 + 1);
    for(int i = 1; i <= 9; i++) ways[i] = 1;
    for(int i = 10; i <= n; i++){
        // calc maximum digit
        ways[i] = 1 + ways[i - maxDig(i)];
    }
    cout << ways[n] << endl;
    return 0;
}