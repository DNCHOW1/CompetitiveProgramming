#include "bits/stdc++.h"

using namespace std;

const int N = 2e5 + 1; // between 2 and this upper bound N
long long TOMOD = 998244353;
long long dp[N]{};
long long prefix[N]{};

int l[11]{};
int r[11]{};

long long add(long long i, long long j){ // both the functions need parenthesis in order to evaluate properly
    if((i += j) >= TOMOD) i -= TOMOD;
    return i;
}

long long sub(long long i, long long j){
    if((i -= j) < 0) i += TOMOD;
    return i;
}

// long long add(long long i, long long j){
//     if((i+=j) >= TOMOD) i -= TOMOD;
//     return i;
// }

// long long sub(long long i, long long j){
//     if((i -= j) < 0) i += TOMOD;
//     return i;
// }


int main(){
    int n, k; cin >> n >> k;
    for(int i = 1; i <= k; i++){
        cin >> l[i] >> r[i];
    }

    // l and r will be the prefix-sum bounds? YES
    dp[1] = 1;
    prefix[1] = 1;  
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(i - l[j] < 0){
                continue;
            }
            // dp[i] += (prefix[i - l[j]] - prefix[max(0, i - r[j] - 1)]);
            dp[i] = add(dp[i], sub(prefix[i - l[j]], prefix[max(0, i - r[j] - 1)]));
        }
        prefix[i] = add(dp[i], prefix[i-1]);
    }
    cout << dp[n] << endl;
    return 0;
}