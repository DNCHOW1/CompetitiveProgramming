#include "bits/stdc++.h"

using namespace std;

const int LARGE = (1 << 20);

int weights[21]{};
int rides[LARGE]{};
int amt[LARGE]{};

int main(){
    int n, x;
    cin >> n >> x;

    for(int i = 0; i < n; i++){
        cin >> weights[i];
    }

    amt[0] = 1e9 + 15;
    for(int i = 1; i < (1 << n); i++){
        rides[i] = 1e9 + 15; amt[i] = 1e9 + 15;
        for(int j = 0; j < n; j++){
            if((i & (1 << j))) {// have to check if bit is on and if 
                int currR = rides[i & ~(1 << j)];
                int currA = amt[i & ~(1 << j)];
                if(currA + weights[j] > x){
                    currR++;
                    currA = min(currA, weights[j]);
                } else{
                    currA += weights[j];
                }

                if(currR < rides[i] || (currR == rides[i] and currA < amt[i])){
                    rides[i] = currR;
                    amt[i] = currA;
                }
            }
        }
    }

    cout << rides[(1 << n) - 1] << endl;
    return 0;
}