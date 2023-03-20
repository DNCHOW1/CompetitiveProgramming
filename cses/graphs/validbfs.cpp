#include <iostream>
#include <bits/stdc++.h>

using namespace std;


// Approach 1 using my original method with sets
int main(){
    const int CON = 2e5 + 1;
    bool visited[CON]{};
    int traversal[CON];
    vector<set<int>> adj_list(CON, set<int>());
    int n, a, b, num, front;
    cin >> n; 
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        adj_list[a].insert(b);
        adj_list[b].insert(a);
    }

    cin >> num;
    if(num != 1){
        cout << "No" << endl;
        return -1;
    }
    queue<int> q;
    set<int>* leaves = &adj_list[1];
    (*leaves).insert(0);
    visited[1] = 1;
    q.push(1);
    int i = 0;

    
    while(!q.empty()){


    }

    /*(*leaves).erase(2);
    for(set<int>::iterator i = adj_list[1].begin(); i != adj_list[1].end(); i++){
        cout << *i << endl;
    }*/
    return 0;
}