#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Could be possible that multiple street lights can be added to the same position

int main(){
    int x, n;
    cin >> x >> n;
    set<int> lights{0, x};
    vector<int> lightsArr;
    vector<int> gaps(n); // Not used to keep track of the gap between 2 lights, that's useless.
                         // Whenever whole problem is solved backwards, when streetlights are removed subsequent gap ++
                         // ONLY whenever this happens should we compare it to the previous max, otherwise no

    int temp, max_gap = 0;
    for(int i = 0; i < n; i++){
        cin >> temp;
        lightsArr.push_back(temp);
        lights.insert(temp);
    }

    int prev = 0;
    for(int light: lights){
        max_gap = max(max_gap, light - prev);
        prev = light;
    }


    for(int i = n - 1; i >= 0; i--){
        gaps[i] = max_gap;
        int lightToRemove = lightsArr[i];
        lights.erase(lightToRemove);
        auto it = lights.upper_bound(lightToRemove);
        int upper = *it;
        int lower = *(--it);
        max_gap = max(max_gap, upper-lower);
    }

    for(int gap: gaps) cout << gap << " ";
    return 0;
}