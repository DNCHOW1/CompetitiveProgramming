#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    /*
    Notes After:
    - Need to convert to a long long because the numbers are 1e18
    - Binary search can be used to search for answer, think of good#'s - index of exclude arr. That's a function
    - There can be excluded numbers from 1 -> 1e18. In that case, r would have to be 2e18! This is because K can be 1e18!
    */

    int n, q;
    long long k;
    cin >> n >> q;
    vector<long long> arr = vector<long long>(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    while(q--){
        cin >> k;
        long long l = 1, r = 2e18 + 1, mid;
        while(l < r){
            mid = l + (r-l)/2;
            int index = upper_bound(arr.begin(), arr.end(), mid) - arr.begin();
            if(mid - index >= k){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        cout << l << endl;
    }
    return 0;
}