#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, num, tempSum=0, maxSum=0;
    cin >> n;
    cin >> num;
    tempSum = maxSum = num;
    for(int i = 0; i < n-1; i++){
        cin >> num;
        tempSum = max(num, num+tempSum);
        maxSum = max(tempSum, maxSum);
    }
    cout << maxSum << endl;
    return 0;
}