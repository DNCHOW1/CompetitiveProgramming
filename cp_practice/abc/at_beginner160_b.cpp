#include "bits/stdc++.h"

using namespace std;

int main(){
    long long x;
    cin >> x;
    long long hap = 0;
    hap += (x/500)*1000;
    x %= 500;
    hap += (x/5)*5;
    cout << hap << endl;
    return 0;
}