#include "bits/stdc++.h"

using namespace std;

const unsigned int LARGE = 2e5 + 1;
int arr[LARGE]{};

/*
TAKEAWAYS:
    * Having a CCW direction was redundant, because on the next index the CW would cover the previous CCW direction
    * Modular something something is tricky with a circle BUT only for the case where you might have to pass through center
    * Using a whiteboard is probably the best to get ideas down and remember them
*/

int main(){
    int k, n;
    cin >> k >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    // Start has to be near the end index in array
    // This includes wrap around

    // If going ccw...
    // (20 - 15) + (15 - 5) = Total Distance 15
    // OR...


    // CCW is the index in front of curr: Take (total perim - front) + curr
    // CW is the index behind curr: Take (total perim - behind) - curr
    int totalD = 1e9 + 7;
    for(int i = 0; i < n; i++){
        int ccwI = (i + 1)%n;
        if(i != n-1){
            totalD = min(totalD, k - arr[ccwI] + arr[i]);
        }else{
            totalD = min(totalD, arr[i] - arr[ccwI]);
        }
    }

    for(int i = 0; i < n; i++){
        int cwI = i - 1;
        if(i != 0){
            totalD = min(totalD, k + arr[cwI] - arr[i]);
        }else{
            cwI = n - 1;
            totalD = min(totalD, arr[cwI] - arr[i]);
        }
    }
    cout << totalD << endl;
    return 0;
}