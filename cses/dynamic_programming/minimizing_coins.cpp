#include "bits/stdc++.h"

using namespace std;

const int N = 1e6 + 1;
long long dp[N];
int coins[100]{};

int main(){
    int n,x;
    cin >> n >> x; // # coins and desired amount

    for(int i = 1; i <= n; i++) cin >> coins[i];

    for(int i = 1; i <= x; i++){
        dp[i] = 1e12;
    }
    dp[0] = 0;
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= n; j++){
            if(coins[j] > i){
                continue;
            }
            dp[i] = min(dp[i], 1+dp[i - coins[j]]);
        }
    }
    // for(int i = 0; i <= x; i++) cout << dp[i] << " ";
    // cout << endl;
    cout << ((dp[x] != 1e12) ? dp[x]:-1) << endl;
    return 0;
}