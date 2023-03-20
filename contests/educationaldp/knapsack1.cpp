#include "stdio.h"
#include <bits/stdc++.h>

#define w first
#define v second

using namespace std;

const int large = 10e5 + 1;

bool trueVal(pair<int, int> i, pair<int, int> j){
    return ((float)i.v/i.w) > ((float)j.v/j.w);
}

int main(){
    int n, w;
    cin >> n >> w;
    //vector<pair<int, int>> items(n);
    long long dp[large]{};
    for(int i = 0; i < n; i++){
        int weight, val;
        cin >> weight >> val;

        for(int j = w; j >= 0; j--){
            if(j - weight >= 0) dp[j] = max(dp[j-weight] + val, dp[j]);
        }
    }
    
    cout << dp[w] << endl;
    return 0;
}