#include "bits/stdc++.h"

using namespace std;

const unsigned int LARGE = 2e3 + 1;
int arr[LARGE][LARGE]{};
int cnt[LARGE]{};

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    // for(int i = 1; i < n; i++) arr[i][i+1] = 1;
    // arr[x][y] = 1;

    // Imagine you're using upper right of 2d array
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            int val = min(j - i, abs(x - i) + 1 + abs(y - j));
            arr[i][j] = val;
            cnt[val]++;
        }
    }
    
    for(int i = 1; i < n; i++){
        cout << cnt[i] << endl;
    }
    return 0;
}