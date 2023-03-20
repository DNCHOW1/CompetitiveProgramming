#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, a, b;
    cin >> n >> m;
    vector <vector<int>> adj_list(n+1, vector<int>());
    int seen[100001]{};
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    // BFS from 1 -> n
    queue<int> q;
    q.push(1);
    int front;
    while(!q.empty()){
        front = q.front();
        q.pop();
        for(int connect: adj_list[front]){
            if(!seen[connect]){
                seen[connect] = front;
                q.push(connect);
                if(connect == n){
                    // Connection exists
                    int count = 1, curr;
                    stack<int> s;
                    curr = connect;
                    while(curr != 1){
                        s.push(curr);
                        curr = seen[curr];
                        count++;
                    }
                    cout << count << endl;
                    cout << 1 << " ";
                    while(!s.empty()){
                        front = s.top();
                        s.pop();
                        cout << front << " ";
                    }
                    cout << endl;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}