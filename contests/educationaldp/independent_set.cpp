#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1e5 + 1;
long long mod = 1e9 + 7;

int dp[MAXN][2]{};
bool visited[MAXN]{};
vector<vector<int>> graph;

// these two functions imported from editorial, trying to figure out where my mod arithmetic is going wrong
int add(int i, int j) {
	if ((i += j) >= mod)
		//i -= mod;
        i %= mod;
	return i;
}
int mul(int i, int j) {
	return int((long long) i * j % mod);
}

// memoization method, suspect it's not working for cases with modulo
long long solve(int node, bool set){ // When calling solve it should also modulo it immediately
    if(dp[node][set]){
        return (dp[node][0] + ((set) ? 0 : dp[node][1])) % mod;
    }

    visited[node] = 1;
    int zeroB = 1, oneB = 1; // different branches
    for(int adj: graph[node]){
        // The commented code gets 14 WA as a result of modulo interaction in P
        // HOWEVER, the uncommented code works. Why???
        /* 
            Possible Explanations:
                - 

        */
        if(!visited[adj]){
            // zeroB *= (solve(adj, 0) % mod);
            // oneB *= (solve(adj, 1) % mod);
            // zeroB %= mod;
            // oneB %= mod;
            zeroB = zeroB * (solve(adj, 0) % mod) % mod;
            oneB = oneB * (solve(adj, 1) % mod) % mod;
        }
    }
    dp[node][0] = zeroB; dp[node][1] = oneB;

    return (dp[node][set] + dp[node][!set]) % mod;
}

// Tabulation method, not really hard to conceptuallize now once I thought of recurrence relation
// Knew the recurrence relation before I viewed analysis from the editorial
/*
void dfs(int curr, int par){

    dp[curr][0] = dp[curr][1] = 1; // nice one-liner I saw from editorial
                                   // What's different is that in my initial implementation
                                   // 0 is white, and 1 is black
    for(int adj: graph[curr]){
        if(adj != par){
            dfs(adj, curr);
            // dp[curr][0] = mul(dp[curr][0], add(dp[adj][0], dp[adj][1]));
            // dp[curr][1] = mul(dp[curr][1], dp[adj][0]);
            dp[curr][0] = (dp[curr][0] * (dp[adj][0] + dp[adj][1] % mod)) % mod; // When the code is like this it works
            dp[curr][1] = (dp[curr][1] * (dp[adj][0] % mod)) % mod;
        }
    }
}
*/

int main(){
    int n;
    cin >> n;
    graph = vector<vector<int>>(n + 1, vector<int>());
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cout << solve(1, 0) << endl;
    // dfs(1, 0);
    // cout << (dp[1][0] + dp[1][1]) % mod << endl;
    return 0;
}