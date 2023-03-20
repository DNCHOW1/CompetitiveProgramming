#include "stdio.h"
#include <bits/stdc++.h>

using namespace std;

const int large = 10e5 + 1;

long double dp[3001][3001]{};
double arr[3001];

int main(){
    // n coins numbered 1-N
    // always be odd, <= 2999 and >=1
    // head p, tails 1-p
    // p real # and 2 decimal places
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    dp[0][0] = 1.0;
    int leastHeads = (n / 2) + 1;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = (1-arr[i])*dp[i-1][j];
            if(j != 0) dp[i][j] += arr[i]*dp[i-1][j-1];
        }
    }

    long double res = 0;
    for(int i = leastHeads; i <= n; i++) res += dp[n][i];

    cout << fixed << setprecision(10) << res << endl;
    // output correct when abs error not greater than 10e-9
    return 0;
}