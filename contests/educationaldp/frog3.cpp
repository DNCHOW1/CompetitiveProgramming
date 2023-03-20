#include "stdio.h"
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, c;
    cin >> n; // n >= 2, <= 2*10^5
    cin >> c; // c >= 1, <= 10^12
              // HEIGHTS IN ARR ARE SORTED!!!

    vector<int> arr(n);
    vector<unsigned int> cost(n, UINT_MAX);
    for(int i = 0; i < n; i++) cin >> arr[i];

    cost[0] = 0;
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= c && i-j >= 0; j++){
            cost[i] = min(cost[i], cost[i-j] + abs(arr[i] - arr[i-j]));
        }
    }

    cout << cost[n-1] << endl;
    return 0;
}