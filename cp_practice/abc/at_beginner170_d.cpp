#include "bits/stdc++.h"

using namespace std;

const unsigned int LARGE = 1e6 + 1;
int arr[LARGE]{};

// If the current is divisible by previous, shouldn't even continue: it's factors are also divisible by previous
// 

int main(){
    int n;
    cin >> n;
    vector<int> input;
    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        input.push_back(temp);
    }

    sort(input.begin(), input.end());
    int maxNum = input[input.size() - 1];
    int ans = 0;

    for(int i = 0; i < input.size() - 1; i++){
        int num = input[i];
        if(arr[num] == 0){ // Check if current number is prime OR no divisors previously
            for(int j = num; j <= maxNum; j+=num){
                arr[j]++;
            }

            // Increment ans here
            if(arr[num] == 1 && input[i] != input[i+1]) {
                ans++;
            }
        }
    }
    ans += (arr[maxNum] == 0);
    // for(int i = 0; i < (maxNum+1); i++) cout << arr[i] << " ";
    // cout << endl;
    cout << ans << endl;
    return 0;
}