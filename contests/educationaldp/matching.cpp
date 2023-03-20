#include "bits/stdc++.h"

using namespace std;

long long TOMOD = 1e9 + 7;

bool compat[22][22]{};
int dp[(1 << 21)];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> compat[i][j];
        }
    }


    dp[0] = 1;
    for(int i = 1; i < (1 << n); i++){ // Iterate through the subsets
        int x = __builtin_popcount(i); // will refer to the row
        for(int j = 0; j < n; j++){
            if(compat[x-1][j] && (i & (1 << (n-j-1)))){ // check if see if bit associated with column set(not used) or not
                dp[i] += dp[i & ~(1 << (n-j-1))];
                dp[i] %= TOMOD;
            }
        }
    }

    cout << dp[(1 << n) - 1] << endl;
    return 0;
}