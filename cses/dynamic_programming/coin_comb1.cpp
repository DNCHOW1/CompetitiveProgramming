#include <bits/stdc++.h>
#include "stdio.h"

using namespace std;
using ll = long long;

ll MOD = 10e9 + 7;

ll dp[(int)1e6 + 10];
vector<int> coins;

ll calc(int x){
    if(x < 0){
        return 0;
    }
    if(dp[x] != -1){
        return dp[x];
    }
    if(x == 0) { return 1; }
    ll ans = 0;
    for(int c: coins){
        ans = (ans + calc(x - c)) % MOD;
    }
    dp[x] = ans;
    return ans;
}

int main(){
    int n, x;
    cin >> n >> x;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++){
        int c; cin >> c;
        coins.push_back(c);
    }
    // cout << calc(x) << endl;
    /*
        f[y] => sets consisting of coins from the list coins 
                whose sum is y
        f[y] = sum_{i} ( f(y - coins[i]) )
    */
    vector<int> f(x+1);
    f[0] = 1;

    for(int y = 1; y <= x; ++y){
        // f[y] = sum_{i} ( f(y - coins[i]) )
        for(int i = 0; i < n; i++){
            if(y - coins[i] >= 0) f[y] += f[y-coins[i]];
            // adding all the sets where the last coin is coin i
            // at this point in time, f[y-coins[i]] counts all the sets
            // ...
        }
        // f[y] is computed
        // after this point, f[y] never changes
    }
    return 0;
}