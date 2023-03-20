#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct DSU{
    vector<int> e;
    DSU(int n) : e(vector<int>(n+1, -1)) {}
    int get(int num){ return (e[num] < 0) ? num: e[num] = get(e[num]); }
    int size(int num){ return -e[get(num)]; }
    bool merge(int a, int b){
        int x = get(a), y = get(b);
        if(x == y) return false;
        if(size(x) > size(y)) swap(x, y);
        e[y] += e[x];
        e[x] = y;
        return true;
    }
    void getGroups(set<int> &groups){
        for(int i = 1; i < e.size(); i++){
            if(e.at(i) < 0){
                groups.insert(-e.at(i));
            }
        }
    }
};

int main(){
    int n, m, a, b;
    cin >> n >> m;
    DSU dsu(n);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        dsu.merge(a, b);
    }
    set<int> groups;
    dsu.getGroups(groups);
    int prev = 0, total = 0;
    for(int size: groups){
        total += size-prev;
        prev = size;
    }
    cout << total << endl;
    return 0;
}