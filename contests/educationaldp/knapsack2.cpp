#include "stdio.h"
#include <bits/stdc++.h>

#define w first
#define v second

using namespace std;

const unsigned int large = 10e5 + 1;

long long v[101]{};
long long w[101]{};
long long dp[large]{};

int main(){
    int n, we;
    cin >> n >> we;
    for(int i = 0; i < n; i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 0; i < large; i++) dp[i] = 1e12;
    dp[0] = 0;

    // Slight shift in thinking
    // max value is 10^3 and there's a max of 100 items
    // that means that 10^5 is the max sum of values to be outputted
    // dp now holds weights, and trying to minimize weights at each index(which now refers to value)

    // ATTEMPT AT EDITORIAL APPROACH
    // Outer loop should be the items! Basically like knapsack 1 but with a twist.
    // TAKEAWAY: Knapsack-like problems 2d table and loop order matters.
    // With item loop inner, you could have dupes
    // with it outer, you can be sure it hasn't been used yet
    for(int i = 0; i < n; i++){
        for(int j = large - 1; j > 1; j--){
            
            if(j - v[i] >= 0){
                dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
            }
        }
    }

    for(int i = large - 1; i > 1; i--){
        if(dp[i] <= we){
            cout << i << endl;
            break;
        }
    }


    // ORIGINAL APPROACH
    // Close to solution, but not quite because couldn't deal with
    // duplicate items being used. THIS IS BECAUSE OF ITEM LOOP BEING ON INNER!!!
    /*
    pair<int, int> inputs[101];
    long long dp[large]{};
    for(int i = 1; i < large; i++){
        dp[i] = 10e12 + 1;
    }

    for(int i = 0; i < n; i++){
        int weight, val;
        cin >> weight >> val;
        inputs[i] = {weight, val};
    }
    
    for(int V = 0; V < large; V++){
        for(pair<int, int> &item: inputs){ // & makes it so you work directly with the elements, instead of copy
            if(V - item.v >= 0){
                dp[V] = min(dp[V], dp[V - item.v] + item.w);
            }
        }
    }

    for(int V = large - 1; V >= 0; V--){
        if(dp[V] <= we){
            cout << V << " " << dp[V] << endl;
        }
    }
    //cout << dp[w] << endl;*/
    return 0;
}