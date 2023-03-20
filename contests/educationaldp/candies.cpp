#include "stdio.h"
#include <bits/stdc++.h>

#define w first
#define v second

using namespace std;

const unsigned int large = 10e5 + 1;
int arr[large]{};
long long dp[large]{};

long long TOMOD = 1000000007;

long long add(long long i, long long j){
    if((i+=j) >= TOMOD) i -= TOMOD;
    return i;
}

long long subtract(long long i, long long j){
    if((i -= j) < 0) i += TOMOD;
    return i;
}

int n, k; // n refers to the # of children, k refers to total candies to share
          // 1 <= n <= 100
          // 0 <= K <= 1e5
          // 0 <= a_i <= K

          // Each child must share 0 to a_i candies, inclusive

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    dp[0] = 1;
    
    for(int i = 1; i <= n; i++){ // iterate through elements in the array
        int p2 = k, p1 = k; // Sliding window technique to get the sums; p2 is leftmost, p1 is rightmost.
                        // Moves right to left
        long long total = 0;
        
        for(; p2 >= k - arr[i]; p2--) {
            //total = (total + dp[p2]) % TOMOD; // Get the initial sum
            total = add(total,dp[p2]);
        }
        p2++; // to be inclusive of window
        // cout << "p" << endl;
        while((p1 - p2) != 0){
            int temp = total;
            if(p2 != 0){ // Don't change p2 anymore, only change p1
                --p2;  
                // total = (total + dp[p2]) % TOMOD;
                total = add(total, dp[p2]);
            }
            // total = (total - dp[p1]) % TOMOD;
            total = subtract(total, dp[p1]);
            dp[p1--] = temp;
        }

        // for(int j = 0; j <= k; j++) cout << dp[j] << " ";
        //cout << endl;
    }
    cout << dp[k] << endl;


    return 0;
}