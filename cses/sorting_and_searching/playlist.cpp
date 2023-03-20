#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, temp;
    vector<int> arr;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    set<int> storing;
    int l = 0, r = 0, lowest = 0;
    while(r != n){
        if(storing.count(arr[r]) == 1){
            while(arr[l] != arr[r]){
                storing.erase(arr[l++]);
            }
            l++;
        }
        storing.insert(arr[r]);
        lowest = max(lowest, r - l + 1);
        r++;
    }
    cout << lowest << endl;
    return 0;
}