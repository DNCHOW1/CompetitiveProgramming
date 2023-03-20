#include "bits/stdc++.h"

using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    if(y % 2 == 1 || 4*x < y){
        cout << "No" << endl;
    } else{
        for(int i = 0; i <= x; i++){
            if(2 * (x - i) + 4*i == y){
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
    }
    return 0;
}