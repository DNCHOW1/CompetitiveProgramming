#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, temp;
    vector<int> arr;
    cin >> n;
    vector<bool> seen = vector<bool>(n+1);
    while(n--) {
        cin >> temp;
        arr.push_back(temp);
    }
    

    long long count = 0;
    for(int num: arr){
        count += (seen[num-1] == false);
        seen[num] = true;
    }
    cout << count << endl;
    return 0;
}