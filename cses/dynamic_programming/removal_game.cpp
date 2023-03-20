#include "bits/stdc++.h"

using namespace std;

//int arr[5001]{};
long long dp1[5001][5001]{};

long long solve(int i, int j, long long total){ // i refers to left bound inclusive, j right bound inclusive
    if(dp1[i][j] != -1e12 - 7){ // check to see if this was computed already
        return dp1[i][j];
    }

    dp1[i][j] = total - min(solve(i+1, j, total - dp1[i][i]), solve(i, j-1, total - dp1[j][j]));
    // dp2[i][j] = total - dp1[i][j];
    // return (first) ? dp1[i][j]: dp2[i][j];
    return dp1[i][j];
}

int main(){

    int n;
    cin >> n;
    long long total = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dp1[i][j] = -1e12 - 7;
        }
    }
    for(int i = 1; i <= n; i++){
        cin >> dp1[i][i];
        total += dp1[i][i];
    }

    
    cout << solve(1, n, total) << endl;
    return 0;   
}
