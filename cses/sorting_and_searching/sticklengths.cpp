#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int constant = 2e5 + 1;
int arr[constant]{};
int n;

bool nextGreater(int num){
    long long sum1=0, sum2=0;
    for(int i = 0; i < n; i++){
        sum1 += abs(num-arr[i]);
        sum2 += abs(num-arr[i] + 1);
    }
    return sum1 <= sum2;
}

int main(){
    int num, left=1e9, right=0, mid;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        arr[i] = num;
        left = min(left, num);
        right = max(right, num);
    }

    while(left < right){
        mid = left + (right - left)/2;
        if(nextGreater(mid)){
            right = mid;
        } else{
            left = mid+1;
        }
    }

    // Calculate Cost
    long long costF = 0;
    for(int i = 0; i < n; i++){
        costF += abs(left - arr[i]);
    }
    cout << costF << endl;
    return 0;
}