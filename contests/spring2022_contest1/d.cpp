#include "bits/stdc++.h"

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    set<int> memo;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        memo.insert(tmp);
        if(memo.size() > k){
            memo.erase(*memo.begin());
        } 
        if(memo.size() == k){
            cout << *memo.begin() << endl;
        }
        // if(i >= k - 1){
        //     auto it = memo.end();
        //     for(int j = 0; j < k; j++) it--;

        //     cout << *it << endl;
        // }
    }
    return 0;
}