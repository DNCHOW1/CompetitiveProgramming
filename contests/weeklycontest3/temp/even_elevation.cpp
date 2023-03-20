#include <iostream>
#include <bits/stdc++.h>

#define ii pair<int, int>
#define f first
#define s second

using namespace std;

array<int, 100001> color{};
vector<vector<ii>> adj_list;
array<int, 100001> arr{};
    

void dfs(int num, int gr){
    arr[num] = 1;
    color[num] = gr;
    for(auto pai: adj_list[num]){
        if(!arr[pai.f]){
            dfs(pai.f, (pai.s%2) ? !gr:gr);
        }
    }
}

int main(){
    int n, u, v, w;
    cin >> n;
    arr.fill(0);
    adj_list = vector<vector<ii>>(n+1, vector<ii>());
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }
    // It's assumed that 1 will connect to all the nodes? But how?
    // Is it because they say it's a tree, it must have root node to all other nodes?
    // In that case, insteado f for loop...
    dfs(1, 1);
    for(int i = 1; i < n + 1; i++){
        cout << color[i] << endl;
    }
    return 0;
}

/*int main(){
    // Implementation trying to do 1 at a time
    int n, u, v, w;
    cin >> n;
    int count = n;
    array<int, 100001> arr{};
    arr.fill(-1);
    vector<vector<int>> adj_list(n+1, vector<int>());
    while(count){
        cin >> u >> v >> w;
        count = count - (arr[u]==-1) - (arr[v]==-1);
        if(w%2){ // Odd length, v and u must be diff
            // The 2 must be differing colors
            if(arr[u] > -1 || arr[v] > -1){
                if(arr[u] > -1){
                    arr[v] = !arr[u];
                }else{
                    arr[u] = !arr[v];
                }
            }else{
                arr[u] = 1;
                arr[v] = 0;
            }
        }else{ // Even length, u and v must be == coloring
            // THe 2 must be the same color
            if(arr[u] > -1 || arr[v] > -1){
                arr[u] = max(arr[u], arr[v]);
                arr[v] = max(arr[u], arr[v]);
            }else{
                arr[u] = 1;
                arr[v] = 1;
            }
        }
    }
    for(int i = 1; i < n+1; i++){
        cout << arr[i] << endl;
    }
    return 0;
}*/