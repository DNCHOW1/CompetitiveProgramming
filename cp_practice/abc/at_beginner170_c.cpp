#include "bits/stdc++.h"

using namespace std;


int arr[101]{};
set<int> seq;

int main(){
    int x, n;
    cin >> x >> n;
    for(int i = 1; i <= n; i++) {
        int temp; cin >> temp;
        arr[temp] = 1;
        // seq.insert(temp);
    }

    int minDist = 1000000;
    int num = -22;
    for(int i = -5; i <= 105; i++){
        if((!arr[i] || i <= 0 || i > 100) && abs(i - x) < minDist){
            minDist = abs(i - x);
            num = i;
        }
    }
    cout << num << endl;
    return 0;
}