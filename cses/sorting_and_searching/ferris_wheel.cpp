#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    // # of children, max allowed weight
    int n, x, num;
    cin >> n >> x;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    int l = 0, r = arr.size()-1, count = 0;
    while(l < r){
        int res = (arr[l] + arr[r]);
        if(res <= x){
            count++;
            l++;
            r--;
        } else if(res > x){
            count++;
            r--;
        }
    }
    cout << count + (l == r) << endl;
    return 0;
}