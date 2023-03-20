#include "stdio.h"
#include <bits/stdc++.h>

#define w first
#define v second

using namespace std;

int main(){
    int num = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 1; j <= i; j++){
            num++;
        }
    }
    cout << num << endl;
    return 0;
}