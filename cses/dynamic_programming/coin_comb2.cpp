#include <bits/stdc++.h>
#include "stdio.h"

using namespace std;
using ll = long long;

ll MOD = 10e9 + 7;

ll dp[100][(int)1e6 + 10];
vector<int> coins;

ll calc(int i, int x){
    if(x == 0) { return 1; }
    if(x < 0){
        return 0;
    }
    if(i >= coins.size()){
        return 0;
    }
    if(dp[i][x] != -1){
        return dp[i][x];
    }
    ll ans = 0;
    int c = coins[i];
    ans = (ans + calc(i, x - c)) % MOD;
    //ans = (ans + calc(i + 1, x - c)) % MOD;
    ans = (ans + calc(i + 1, c)) % MOD;
    dp[i][x] = ans;
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
    //cout << calc(0, x) << endl;

    vector<int> f(x+1);
    f[0] = 1;

    for(int i = 0; i < n; i++){
        // f[y] = sum_{i} ( f(y - coins[i]) )
        for(int y = 1; y <= x; ++y){
            if(y - coins[i] >= 0) f[y] += f[y-coins[i]];
            // adding all the sets where the last coin is coin i
            // at this poiint in time, f[y-coins[i]] coutns all the sets
            // consisting of coins [0, i] whose sum is y-coins[i]
        }
        // f[y] is computed
        // currently, it stores the # of sets
        // whose sum is y and consist of only the first i+1 coins
    }
    return 0;
}