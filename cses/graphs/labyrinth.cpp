#include <iostream>
#include <bits/stdc++.h>

#define ii pair<int, int>
#define f first
#define s second

using namespace std;

int main(){
    int n, m;
    ii start = {1002, 1002}, front, curr;
    vector<string> maze;
    char seen[1000][1000];
    int parent[1000][1000];

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    string dir = "DURL", temp;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> temp;
        maze.push_back(temp);
        if(start.f == 1002){
            for(int j = 0; j < m; j++){
                if(maze[i][j] == 'A'){
                    start = {i, j};
                    seen[i][j] = ' ';
                }
            }
        }
    }

    queue<ii> q;
    q.push(start);
    while(!q.empty()){
        front = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int newI = front.f+dr[i], newJ = front.s+dc[i];
            if(newI >= 0 && newI < n && newJ >= 0 && newJ < m){
                if(!seen[newI][newJ] && maze[newI][newJ] != '#'){
                    seen[newI][newJ] = dir[i];
                    parent[newI][newJ] = i;
                    if(maze[newI][newJ] == 'B'){
                        int prev;
                        string ret = "";
                        curr = {newI, newJ};
                        while(curr.f != start.f || curr.s != start.s){
                            ret += seen[curr.f][curr.s];
                            prev = parent[curr.f][curr.s];
                            curr = {curr.f - dr[prev], curr.s - dc[prev]};
                        }
                        cout << "YES" << endl;
                        cout << ret.size() << endl;
                        reverse(ret.begin(), ret.end());
                        for(char c: ret){
                            cout << c;
                        }
                        cout << endl;
                        return 0;
                    }
                    q.push({newI, newJ});
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}