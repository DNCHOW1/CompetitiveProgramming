#include "bits/stdc++.h"

using namespace std;

const int N = 2001;
long long mod = 1e9 + 7;
long long dp[N]{};


int main(){
    int n; cin >> n;
    dp[0] = 1;

    for(int i = 3; i <= n; i++){
        for(int j = 3; i - j >= 0; j++){
            dp[i] += dp[i-j]; // could form a prefix-sum instead
            dp[i] %= mod;
        }
    }

    cout << dp[n] << endl;
    return 0;
}