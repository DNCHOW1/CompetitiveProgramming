#include "stdio.h"
#include <bits/stdc++.h>

#define w first
#define v second

using namespace std;

const unsigned int large = 10e5 + 1;
long long dp[3001][3001]; // If defined in main it leads to segmentation fault
                      // HOWEVER, defined up here is fine???
int n;
long long arr[3001];

// define memo function here
//
long long calcScore(int i, int j){ // i refers to front index, j refers to back index
                                   // initially, i will be 1 and j will be n
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    dp[i][j] = max(arr[i] - calcScore(i + 1, j), arr[j] - calcScore(i, j - 1));
    return dp[i][j];
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // populate dp array with -1(not calculated yet)
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = (i == j) ? arr[i] : -1;
        }
    }
    
    cout << calcScore(1, n) << endl;


    return 0;
}