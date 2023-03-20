#include "stdio.h"
#include <bits/stdc++.h>

using namespace std;

const int large = 10e5 + 1;

int dp[large]{};
int arr[101];
int n, k;

int calcWinner(int pos, bool player){ // memoization
    if(dp[pos] != -1){
        return (dp[pos]) ? player: !player;
    }
    for(int i = 0; i < n && (pos - arr[i]) >= 0; i++){
        if(calcWinner(pos - arr[i], !player) == player){
            dp[pos] = 1;
            return player;
        }
    }
    dp[pos] = 0;
    return !player;
}

int main(){
    // arr will be sorted
    cin >> n >> k; // n >= 2, <= 10^
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = arr[0]; i <= k; i++) dp[i] = -1;

    
    calcWinner(k, 0);
    // for(int i = 0; i <= k; i++) cout << dp[i] << endl;
    if(dp[k]){
        cout << "First" << endl;
    }else{
        cout << "Second" << endl;
    }
    

    return 0;
}