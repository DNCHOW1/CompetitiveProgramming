#include "stdio.h"
#include <bits/stdc++.h>

using namespace std;

const int large = 10e5 + 1;

string graph[1001]{};
unsigned long long dp[1001][1001]{};

int main(){
    // TAKEAWAYS:
    // - When modding the answer in c++, just use exact number instead of the e thing
    // - IN THIS PROBLEM, modding at the end was troublesome
    //   Instead, in the editorial i looked at it seemed better to mod at each step
    //   Some properties of modding probably explain why this still gives the correct answer

    int h, w;
    cin >> h >> w;
    for(int i = 0; i < h; i++) cin >> graph[i];

    dp[1][1] = 1;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(graph[i-1][j-1] == '.'){
                dp[i][j] = max(dp[i][j], dp[i-1][j] + dp[i][j-1]) % 1000000007;
               // printf("%d %d %lld\n", i, j, dp[i][j]);
            }
        }
    }

    // 35345263800
    // 345263555
    unsigned long long toMod = 10e9 + 7; // Have to use exact number or it won't work???
    cout << (dp[h][w] % 1000000007) << endl;
    return 0;
}