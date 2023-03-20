#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    // Sliding window is the correct way to approach; BUT, CAN BE SIMPLIFIED TO TWO POINTERS!!!
    // YOU ONLY CARE ABOUT IF 1 NUMBER IS BIGGER THAN ANOTHER! If it is, bigger product.
    int n, k, num, l = 0;
    long long prev = 1;
    cin >> n >> k;
    array<long long, 200001> arr{};
    for(int i = 0; i < k; i++){
        cin >> num;
        arr[i] = num;
        prev *= num;
    }

    for(int i = k; i < n; i++){
        cin >> num;
        arr[i] = num;
        if(arr[i] > arr[l]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
        l++;
    }

}