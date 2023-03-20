#include "bits/stdc++.h"

using namespace std;

const unsigned int LARGE = 2e5 + 1;

int main(){
    long long n, k;
    long long arr[LARGE]{};
    set<long long> smallest;
    cin >> n >> k;
    long long starting = k / n, left = k % n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        smallest.insert(arr[i]);
        if(smallest.size() > left){
            smallest.erase(--smallest.end());
        }
    }

    for(int i = 0; i < n; i++){
        cout << starting + (smallest.count(arr[i])) << endl;
    }
    return 0;
}