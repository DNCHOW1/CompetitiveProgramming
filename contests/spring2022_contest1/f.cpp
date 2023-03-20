#include "bits/stdc++.h"

using namespace std;

int main(){
    int n;
    // first elem you know will be right, 2nd is (2nd elem + 1st elem) always
    // third elem is (third elem + max(2nd, 1st))

    cin >> n;

    // keep track of max as you go along
    vector<long long> arr(n+1, 0);
    vector<long long> a(n);
    long long biggest = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        int current = arr[i] + biggest;
        biggest = max(biggest, (long long)current);
        
        a[i] = current;
    }
    for(auto i: a) cout << i << " ";
    cout << endl;
    return 0;
}