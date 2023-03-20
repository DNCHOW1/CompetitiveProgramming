#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    map<int, int> hashmap;
    int n, target, num;
    cin >> n >> target;

    for(int i = 0; i < n; i++){
        cin >> num;
        if(hashmap.count(num)){
            cout << i+1 << " " << hashmap[num]+1 << endl;
            return 0;
        }
        hashmap.insert(pair<int, int>(target-num, i));
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}