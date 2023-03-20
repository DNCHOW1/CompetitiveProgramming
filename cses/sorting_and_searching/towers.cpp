#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, temp;
    vector<int> arr;
    cin >> n;
    while(n--){
        cin >> temp;
        int l = 0, r = arr.size();
        while(l < r){
            int mid = l - ((l - r)/2);
            if(arr[mid] <= temp){
                l = mid + 1;
            } else{
                r = mid;
            }
        }
        if(l == arr.size()) { arr.push_back(temp); }
        else{ arr[l] = temp; }
    }
    cout << arr.size() << endl;
    return 0;
}