#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct DSU{
    vector<int> e;
    DSU(int n){e = vector<int>(n + 1, -1);} // C++ Initialization for structs?
    int get(int num){
        // Used for both getting both the size of component(if done to the end) or the parent
        // Uses path compression
        // If negative the number is negation of the size, otherwise index of parent
        if(e[num] < 0){
            return num;
        }
        else{
            e[num] = get(e[num]);
            return e[num];
        }
    }
    int size(int num){return -e[get(num)];}
    bool same_set(int a, int b){ return get(a) == get(b); }
    bool merge(int a, int b){
        int x = get(a), y = get(b);
        if(x == y){ return false; }
        if(size(x) > size(y)){
            swap(x, y);
        }
        e[y] += e[x];
        e[x] = y;
        return true;
    }
};

int main(){
    int n, q, num, a, b;
    cin >> n >> q;
    DSU dsu(n+1);
    for(int i = 0; i < q; i++){
        cin >> num >> a >> b;
        if(num){
            cout << dsu.same_set(a, b) << endl;
        }else{
            dsu.merge(a, b);
        }
    }
    return 0;
}