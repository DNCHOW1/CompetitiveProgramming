#include "bits/stdc++.h"

using namespace std;

const unsigned int LARGE = 2e5 + 3;

int main(){
    // Using prefix-sum, takes O(n + t) runtime
    int n;
    long long w;
    cin >> n >> w;
    vector<long long> prefix(LARGE, 0);
    for(int i = 0; i < n; i++){
        int s, t, p;
        cin >> s >> t >> p;
        prefix[s] += p;
        prefix[t] -= p;
    }

    for(int i = 0; i < LARGE; i++){ // Doesn't take care of the case where start is 0!!
                                    // Must change so that it compares prefix[i] and i starts at 0
        prefix[i+1] += prefix[i];
        if(prefix[i] > w) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;


    // Using simulation and sorting, took O(nlogn)
    // int n;
    // long long w;
    // cin >> n >> w;
    // vector<pair<int, int>> arr;
    // for(int i = 0; i < n; i++){
    //     int s, t, p;
    //     cin >> s >> t >> p;
    //     arr.push_back(make_pair(s, p));
    //     arr.push_back(make_pair(t, -p));
    // }

    // sort(arr.begin(), arr.end());
    // long long total = 0;
    // for(auto [time, value]: arr){
    //     total += value;
    //     if(total > w){
    //         cout << "No" << endl;
    //         return 0;
    //     }
    // }
    // cout << "Yes" << endl;
    return 0;
}