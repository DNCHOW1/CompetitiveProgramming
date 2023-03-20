#include <bits/stdc++.h>

#define ii pair<int, int>
#define f first
#define s second

using namespace std;

int main(){
    int n, m, a, b, front, prev=0;
    cin >> n >> m;
    vector<vector<int>> adj_list(n+1, vector<int>());
    vector<ii> should_connect;
    int seen[100001]{};

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    for(int i = 1; i < n+1; i++){
        if(!seen[i]){
            // Do bfs to populate seen
            queue<int> q;
            seen[i] = 1;
            q.push(i);
            while(!q.empty()){
                front = q.front();
                q.pop();
                for(int connected: adj_list[front]){
                    if(!seen[connected]){
                        seen[connected] = 1;
                        q.push(connected);
                    }
                }
            }
            if(prev != 0){
                should_connect.push_back({prev, i});
            }
            prev = i;
        }
    }

    cout << should_connect.size() << endl;
    for(ii connected_cities: should_connect){
        cout << connected_cities.f << " " << connected_cities.s << endl;
    }
    return 0;
}