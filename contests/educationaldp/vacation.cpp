#include "stdio.h"
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int input[3] = {0, 0, 0};
    for(int i = 0; i < n; i++){
        int a, b, c; cin >> a >> b >> c;
        // do 3 separate conditionals to check current best
        long long newA = a + max(input[1], input[2]);
        long long newB = b + max(input[0], input[2]);
        long long newC = c + max(input[0], input[1]);
        input[0] = newA; input[1] = newB; input[2] = newC;
    }
    cout << max(max(input[0], input[1]), input[2]) << endl;
    return 0;
}