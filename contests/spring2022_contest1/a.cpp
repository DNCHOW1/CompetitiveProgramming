#include "bits/stdc++.h"

using namespace std;

int main(){
    int n;
    string input;
    cin >> n;
    cin >> input;

    // LRLR - 0, -2, -1, 1, 2
    int l = 0, r = 0;
    for(char c: input){
        if(c == 'L'){
            l++;
        } else{
            r++;
        }
    }
    // cout << l << " " << r << endl;
    cout << (l + r + 1) << endl;

    return 0;
}