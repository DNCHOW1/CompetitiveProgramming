#include "bits/stdc++.h"

using namespace std;

const unsigned int LARGE = 1e5 + 1;
int red[LARGE]{};
int green[LARGE]{};
int non[LARGE]{};

/*
Takeaways:
    * Idea was somewhat correct, but failed to take into account TRULY greedy approach
    * Instead of replacing with min sufficient colorless, REPLACE WITH THE MAXIMUM!!!
    * This maximizes the gain!
*/

int main(){
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    for(int i = 0; i < a; i++) cin >> red[i];
    for(int i = 0; i < b; i++) cin >> green[i];
    for(int i = 0; i < c; i++) cin >> non[i];

    sort(red, red + a);
    sort(green, green + b);
    sort(non, non + c);

    int aI = a - x, bI = b - y, cI = c-1;
    long long total = 0;
    while(cI != -1 && aI != a && bI != b){
        if(non[cI] > red[aI] || non[cI] > green[bI]){
            if(red[aI] > green[bI]){ // replace the green
                total += non[cI];
                bI++;
            } else{ // replace the red
                total += non[cI];
                aI++;
            }
            cI--;
        } else{
            total += red[aI++] + green[bI++];
        }
    }
    while(aI != a){
        if(non[cI] > red[aI]){
            total += non[cI--];
        } else{
            total += red[aI];
        }
        aI++;
    }
    while(bI != b){
        if(non[cI] > green[bI]){
            total += non[cI--];
        } else{
            total += green[bI];
        }
        bI++;
    }


    /*while(cI != c && aI != a && bI != b){
        if(non[cI] > red[aI] || non[cI] > green[bI]){
            if(red[aI] > green[bI]){ // replace the green
                total += non[cI];
                bI++;
            } else{ // replace the red
                total += non[cI];
                aI++;
            }
        }
        cI++;
    }
    cout << total << " " << aI << " " << bI << " " << cI << endl;
    while(aI != a) {
        while(cI != c && non[cI] < red[aI]) cI++;

        if(cI != c && non[cI] > red[aI]){
            total += non[cI++];
        } else{
            total += red[aI];
        }
        aI++;
    }
    while(bI != b) {
        while(cI != c && non[cI] < green[bI]) cI++;

        if(cI != c && non[cI] > green[bI]){
            total += non[cI++];
        } else{
            total += green[bI];
        }
        bI++;
    }*/

    cout << total << endl;
    return 0;
}