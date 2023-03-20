#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// The last line is not getting read
// Sets are not used to keep track of visited

string convert_to_string(array<int, 2> pair){
    return to_string(pair[0]) + " " + to_string(pair[1]);
}

void bfs(vector<string> &mat, bool visited[1001][1001], array<int, 2> seed, int n, int m){
    queue<array<int, 2>> que;
    array<int, 2> to_add;
    que.push(seed);
    visited[seed[0]][seed[1]] = true;
    while(!que.empty()){
        auto [r, c] = que.front();
        que.pop();
        for(int i = -1; i < 2; i+=2){
            if(r + i < n && r + i >= 0 && mat[r+i][c] == '.' && !visited[r+i][c]){
                to_add = {r+i, c};
                visited[r+i][c] = true;
                que.push(to_add);
            }
        }
        for(int i = -1; i < 2; i+=2){
            if(c + i < m && c + i >= 0 && mat[r][c+i] == '.' && !visited[r][c+i]){
                to_add = {r, c+i};
                visited[r][c+i] = true;
                que.push(to_add);
            }
        }
        mat[r][c] = '#';
    }
}

int main(){
    int n, m, count = 0;
    string line;
    cin >> n >> m;

    vector<string> matrix;
    bool visited[1001][1001] = {false};

    for(int i = 0; i < n; i++){
        cin >> line;
        matrix.push_back(line);
    }

    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            if(matrix[r][c] == '.'){
                bfs(matrix, visited, {r, c}, n, m);
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}