#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n;
    long long a;
    cin >> n;
    set<int> set;

    for(int i = 0; i < n; i++){
        cin >> a;
        set.insert(a);
    }
    cout << set.size() << endl;
    return 0;
}