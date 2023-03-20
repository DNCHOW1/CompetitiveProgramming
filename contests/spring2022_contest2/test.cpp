#include "bits/stdc++.h"

using namespace std;

const unsigned int LARGE = 2e5 + 1;

int main(){
    vector<int> a = {4, 6, 2, 1, 3};
                  // 3, 2, 4, 0, 1; if leftover is 4, then all of these indices with true index < 4 should be incre
    vector<int> ord(5);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int i, int j) { return a[i] < a[j]; });

    for(auto &x: ord) cout << x << endl;
    return 0;
}