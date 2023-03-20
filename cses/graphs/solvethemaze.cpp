#include <iostream>
#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;

int main(){
    /*
    Notes
    - G and B can't be blocked, BUT can be passed through
    - If B ever next to G (cardinal directions), maze is impossible
        + Therefore, valid mazes must have B on diagonal of G or 1 space between
    - If B is next to target and G in maze, maze is impossible

    Editorial Idea
    - Block cardinal directions of B ONLY if it's == '.'
    - Initialize queue IF AND ONLY IF target is == '.'
    - Floodfill from target position, having another 2d array to keep track of visited
    - Run through 2d arrays. If G and not visited, not good. If B and visited, not good.

    My Idea
    - Block cardinal directions of B, making sure no G nearby
    - If only B in map, block target
    - Floodfill from target and check if all G within reach
    */
    int t, n, m;
    char maze[55][55];
    vector<pair<int, int>> bads;
    vector<pair<int, int>> goods;
    pair<int, int> directions[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> m;
        bads = {};
        goods = {};
        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                cin >> maze[r][c];
                if(maze[r][c] == 'B') bads.push_back({r, c});
                else if(maze[r][c] == 'G') goods.push_back({r, c});
            }
        }

        bool bad = false;
        // Blocking cardinal directions of bad people
        for(auto const& [r, c]: bads){
            for(auto const& [dr, dc]: directions){
                int nr = r+dr, nc = c+dc;
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && maze[nr][nc] != 'B'){
                    if(maze[nr][nc] == 'G'){
                        bad = true;
                    }
                    maze[nr][nc] = '#';
                }
            }
            if(bad) break;
        }

        // Floodfilling from target node to determine if goods reached
        if(!bad && !goods.empty()){
            queue<pair<int, int>> q;
            pair<int, int> front;
            bool visited[55][55]{};
            visited[n-1][m-1] = true;
            q.push({n-1, m-1});
            while(!q.empty()){
                front = q.front();
                q.pop();
                if(maze[front.f][front.s] == '#'){
                    bad = true; // If th target is blocked and good exists
                    break;
                }
                for(auto const& [dr, dc]: directions){
                    int nr = front.f+dr, nc = front.s+dc;
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && maze[nr][nc] != '#'){
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }

            for(auto const& [r,c]: goods){
                if(!visited[r][c]){
                    bad = true;
                    break;
                }
            }
        }
        cout << ((bad) ? "No" : "Yes") << endl;
    }
    return 0;
}