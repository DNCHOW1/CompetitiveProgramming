#include "bits/stdc++.h"

using namespace std;

const unsigned int LARGE = 1e5 + 1;
vector<int> arr;
vector<pair<int, int>> ops;

bool comp_custom(pair<int, int> a, pair<int, int> b){
    return b.second < a.second;
}

/*
Takeaways:
    * If custom comparator true, will put whatever was true before the next
    * Big insight came from keyword: AT MOST. With this, figured out you weren't locked into a choice
        * This, along with me practicing a similar greedy problem previously, allowed the idea
    * Still somewhat slow at implementing the right loops to do what I want. Had the idea but trouble implementing
    * Sorting with static arrays is weird, use a vector instead
*/

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        arr.push_back(temp);
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ops.push_back({a, b}); // sort ops by b
    }

    sort(arr.begin(), arr.end()); // sorted L -> G
    sort(ops.begin(), ops.end(), comp_custom);

    long long total = 0;
    int ind1 = 0, ind2 = 0;
    while(ind1 != n && ind2 != m){
        pair<int, int> curr = ops[ind2];
        while(ind1 != n && curr.first != 0 && curr.second > arr[ind1]){
            total += curr.second;
            ind1++; curr.first--;
        }
        ind2++;
    }
    while(ind1 != n) total += arr[ind1++];

    cout << total << endl;
    return 0;
}