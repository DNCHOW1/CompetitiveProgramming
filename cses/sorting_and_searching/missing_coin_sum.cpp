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
    int n;
    cin >> n;
    v32 coins(n);
    for(auto& x: coins) cin >> x;
    sort(coins.begin(), coins.end()); coins.push_back(INT32_MAX);

    ll currSum = 0;
    for(int i = 0; i < coins.size()-1; i++){
        if(currSum + 1 < coins[i]) break;
        currSum += coins[i];
    }

    cout << currSum+1 << endl;
    return 0;
}