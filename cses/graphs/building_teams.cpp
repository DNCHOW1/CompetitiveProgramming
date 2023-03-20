#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m;
const int mn = 1e5 + 1;
bool bad = false;
array<int, mn> group; // Using 1 or 2 for groups; Array initialized with 0s
vector<vector<int>> adj_list;

void dfs(int n = 1, bool gr = 0){
    // Want gr to oscillate between 1 and 2
    group[n] = gr;
    for(int connected_city: adj_list[n]){
        if(group[connected_city] == -1){
            dfs(connected_city, !gr);
        }else{
            if(group[connected_city] == gr){
                bad = true;
            }
        }
    }
}

int main(){
    int a, b;
    cin >> n >> m;
    group.fill(-1);
    adj_list = vector<vector<int>>(n+1, vector<int>());
    
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    for(int i = 1; i < n + 1 && !bad; i++){
        if(group[i] == -1){
            dfs(i, 1);
        }
    }
    if(bad){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        for(int i = 1; i < n+1; i++){
            if(!group[i]){
                cout << 2 << " ";
            }else{
                cout << 1 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}