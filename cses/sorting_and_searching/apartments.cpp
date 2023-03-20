#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, k, num;
    vector<int> applicants;
    vector<int> sizes;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> num;
        applicants.push_back(num);
    }
    for(int i = 0; i < m; i++){
        cin >> num;
        sizes.push_back(num);
    }
    sort(applicants.begin(), applicants.end());
    sort(sizes.begin(), sizes.end());

    int count = 0, i = 0, j = 0;
    while (i != n && j != m){
        if(abs(applicants[i] - sizes[j]) <= k){
            count++;
            j++;
            i++;
        }else{
            if(sizes[j] > applicants[i]){
                i++;
            }else{
                j++;
            }
        }
    }
    cout << count << endl;
    return 0;
}