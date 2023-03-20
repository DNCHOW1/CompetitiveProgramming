#include "stdio.h"
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n; // n >= 2, <= 10^5
    
    vector<int> arr(n);
    vector<long long> cost(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    cost[0] = 0; cost[1] = abs(arr[1]-arr[0]);
    for(int i = 2; i < n; i++){
        cost[i] = min(cost[i-2] + abs(arr[i] - arr[i-2]), cost[i-1] + abs(arr[i] - arr[i-1]));
    }
    
    cout << cost[n-1] << endl;
    //for(int i = 0; i < n; i++) printf("%lld ", cost[i]);
    // 0 20 30 0 0 10

    return 0;
}