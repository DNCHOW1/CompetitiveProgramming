#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

struct DSU{
    vector<int> e;
    DSU(int n){ e = vector<int>(n+1, -1); }
    int get(int num){
        if(e[num] < 0){
            return num;
        }else{
            e[num] = get(e[num]);
            return e[num];
        }
    }
    int size(int num){ return -e[get(num)]; }
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
    int n, m, q, a, b, num;
    cin >> n >> m;
    unordered_map<int, pair<int, int>> threads;
    //map<int, pair<int, int>> threads;
    stack<pair<int, int>> s;
    pair<int, int> temp;
    DSU dsu(n+1);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        threads[i+1] = {a, b};
    }
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> num;
        temp = threads[num];
        threads.erase(num);
        s.push(temp);
    }

    for(auto it = threads.begin(); it != threads.end(); it++){
        temp = it->second;
        bool cond = dsu.merge(temp.first, temp.second);
        n -= cond;
    }

    /*string out = "";
    while(!s.empty()){
        out += (to_string(n) + " ");
        temp = s.top();
        s.pop();
        bool cond = dsu.merge(temp.first, temp.second);
        n -= cond;
    }
    out.pop_back();
    reverse(out.begin(), out.end());
    cout << out << endl;*/

    vector<int> output;
    while(!s.empty()){
        output.push_back(n);
        temp = s.top();
        s.pop();
        n -= dsu.merge(temp.first, temp.second);
    }
    for(int i = output.size()-1; i>=0; i--){
        cout << output[i];
        if(i != 0){
            cout << " ";
        } else{
            cout << endl;
        }
    }
}