/*
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct DSU{
    vector<int> e;
    DSU(int n) : e(vector<int>(n+1, -1)) {}
    int get(int num){
        if(e[num] < 0) return num;
        e[num] = get(e[num]);
        return e[num];
    }
    int size(int num){ return -e[get(num)]; }
    bool merge(int a, int b){
        int x = get(a), y = get(b);
        if(x == y) return false;
        if(size(x) < size(y)) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

int main(){
    int m, n, a, b;
    cin >> n >> m;
    int components = n, largest = 1;
    DSU dsu(n);


    for(int i = 0; i < m; i++){
        cin >> a >> b;
        if(dsu.merge(a, b)){
            components--;
            largest = max(largest, dsu.size(b));
        }
        cout << components << " " << largest <<  endl;
    }
    return 0;
}
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct DSU{
    vector<int> par;
    vector<int> rank;
    vector<int> sizes;
    void init(int n){
        // Initialization of each number to itself(starting off each city closed off)
        for(int i = 0; i < n+1; i++){
            par.push_back(i);
        }
        rank = vector<int>(n+1, 0);
        sizes = vector<int>(n+1, 1);
    }
    int find(int num){
        // Does implicit path compression
        if(num == par[num]){
            // Num points to itself
            return num;
        }
        par[num] = find(par[num]);
        return par[num];
    }
    int size(int num){
        int root = find(num);
        return sizes[root];
    }
    bool merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b){
            // par[b] = a; // Not Rank based i believe
            if(rank[a] < rank[b]){
                sizes[b] += sizes[a];
                par[a] = b;
            } else if(rank[b] < rank[a]){
                sizes[a] += sizes[b];
                par[b] = a;
            } else{
                sizes[a] += sizes[b];
                par[b] = a;
                rank[a] += 1;
            }
            return true;
        }
        return false;
    }

};

int main(){
    int m, n, a, b;
    cin >> n >> m;
    int components = n, largest = 1;
    DSU union_;
    union_.init(n);


    for(int i = 0; i < m; i++){
        cin >> a >> b;
        if(union_.merge(a, b)){
            components--;
            largest = max(largest, union_.size(b));
        }
        cout << components << " " << largest <<  endl;
    }
    return 0;
}