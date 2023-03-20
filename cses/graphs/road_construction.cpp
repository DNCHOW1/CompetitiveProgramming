#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int bfs(int start, const vector<vector<int>> &adj_arr){
    // utilize an unordered set to check if nodes have been visited <=== Optimization
    queue<int> q;
    unordered_set<int> seen;
    int curr_city, count = 1;
    seen.insert(start);
    q.push(start);

    while(!q.empty()){
        curr_city = q.front();
        q.pop();
        for(int connected_city: adj_arr[curr_city]){
            //cout << "t" << endl;
            if(seen.find(connected_city) == seen.end()){
                //cout << connected_city << endl;
                seen.insert(connected_city);
                count++;
                q.push(connected_city);
            }
        }
    }
    return count;
}

int main(){
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> adj_arr(n+1, vector<int>());

    int largestSize = 1, num_components = n, beforeSize, candidateSize;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        beforeSize = bfs(a, adj_arr);
        adj_arr[a].push_back(b);
        adj_arr[b].push_back(a);
        candidateSize = bfs(a, adj_arr);
        if(candidateSize > largestSize){
            largestSize = candidateSize;
        }
        if(candidateSize > beforeSize){
            num_components--;
        }
        cout << num_components << " " <<  largestSize << endl;
        // num components will either decrease or remain the same
    }   
}