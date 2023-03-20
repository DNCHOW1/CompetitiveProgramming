#include "bits/stdc++.h"

using namespace std;

const int N = 1001;
string arr[N]{};
long long dp[N][N]{};

long long mod = 1e9 + 7;

int main(){
    int n;
    cin >> n; // # coins and desired amount
    for(int i = 0; i < n; i++) cin >> arr[i];

    dp[0][0] = (arr[0][0] == '.');   
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] != '*'){
                if(j != 0){
                    dp[i][j] += dp[i][j-1];
                    dp[i][j] %= mod;
                }
                if(i != 0){
                    dp[i][j] += dp[i-1][j];
                    dp[i][j] %= mod;
                }
            }
            
        }
    } 
    cout << dp[n-1][n-1] << endl;
    return 0;
}