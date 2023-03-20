#include "stdio.h"
#include <bits/stdc++.h>

using namespace std;

const int large = 10e5 + 1;

long long dp[large]{};
vector<vector<int>> graph;

int traverse(int i){
    dp[i] = 0;
    for(int con: graph[i]){
        if(dp[con] == -1) traverse(con);
        dp[i] = max(dp[i], 1 + dp[con]);
    }
    return dp[i];
}

int main(){
    // N vertices and M edges; verts numbered 1->N
    // Graph has no cycles
    // Length of the longest path in graph?

    // vertices could not be connected
    int N, M;
    cin >> N >> M;
    graph = vector<vector<int>>(N+1);

    // Constructing the graph
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for(int i = 0; i <= N; i++) dp[i] = -1;

    long long longest = 0;
    for(int i = 1; i <= N; i++){
        if(dp[i] == -1) traverse(i);
        longest = max(longest, dp[i]);
    }

    // For the problem use memoization
    // Traverse into node IF dp[node] == -1 (not visited); else return that
    cout << longest << endl;
    return 0;
}