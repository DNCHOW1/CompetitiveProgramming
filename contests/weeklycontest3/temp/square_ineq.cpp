#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << ((pow(a, 2) + pow(b, 2) < pow(c, 2)) ? "Yes": "No") << endl;
    return 0;
}