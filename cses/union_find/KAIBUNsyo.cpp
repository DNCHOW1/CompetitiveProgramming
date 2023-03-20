#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;

struct DSU{
    vector<int> e;
    DSU() : e(vector<int>(200005, -1)) {}
    int get(int num){ return (e[num] < 0) ? num: e[num]=get(e[num]); }
    int size(int num){ return -e[get(num)]; }
    bool merge(int a, int b){
        int x = get(a), y = get(b);
        if(x == y) return false;
        if(size(x) > size(y)) swap(x, y);
        e[y] += e[x];
        e[x] = y;
        return true;
    }
    long long getOps(){
        long long ops = 0;
        for(int i = 0; i < e.size(); i++){
            if(e.at(i) < -1){
                ops += (-e.at(i) - 1);
            }
        }
        return ops;
    }
};

int main(){
    /*
    Notes
    - 200000 is considered palindromic

    Idea
    - Iterate from i -> N//2
        + For 5 go up to and include 1, 2 not used()
        + For 6 go up to and include 2
    - Check Ai to Ai(from end), if not palindrome "connect" them with dsu
    - Num ops will be sum of (component_size - 1) where component size >= 2
    */
    cin >> n;
    vector<int> nums = vector<int>(n);
    DSU dsu;
    for(int i = 0; i < n; i++){
        cin >> nums.at(i);
    }

    for(int i = 0; i < (n/2); i++){
        if(nums.at(i) != nums.at(n-i-1)){
            dsu.merge(nums.at(i), nums.at(n-i-1));
        }
    }
    cout << dsu.getOps() << endl;
}