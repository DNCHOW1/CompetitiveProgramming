#include<bits/stdc++.h>
using namespace std;

/*
int main() {
    int n, t;
    cin >> n >> t;

    vector<int> ks(n);
    for (int i = 0; i < n; i++)
        cin >> ks[i];

    long long low = 0;
    long long high = 1e18;

    while (low < high) {
        long long mid = low + (high - low) / 2;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += mid / ks[i];
            if (sum >= t) // needed to prevent overflow
                break;
        }

        if (sum >= t)
            high = mid;
        else
            low = mid + 1;
    }
    cout << low << endl;
}
*/

// Why does above work but mine doesnt?




#include <bits/stdc++.h>

using namespace std;

// For some reason this function doesn't work well, results in long long answer
int calc_products(vector<int> arr, int time, int target){
    // From the given time, will all the devices amount to target product?
    long long total = 0;
    for(int n: arr){
        total += time/n;
        if(total >= target){
            break; // See this a lot in code to prevent overflow error
        }
    }
    return total;
}

int main(){
    int n, t;
    cin >> n >> t;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long long lo = 1, hi = 1e18, mid;
    // Trying to find the minimum time(in seconds) in order to get calc_products == t
    while(lo < hi){
        mid = (lo + hi) / 2;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum += mid/arr[i];
            if(sum >= t)
                break;
        }
        if(sum >= t){
            hi = mid;
        } else{
            lo = mid+1;
        }
    }
    cout << lo << endl;
    return 0;
}
