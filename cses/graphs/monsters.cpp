#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define nl '\n'
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define dbg(x) cerr<<#x<<" = "<<x<<endl

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& pair) {
    return out << '(' << pair.first << ", " << pair.second << ')';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
    if(vec.empty()) return out << "[]";
    out << '[';
    for(size_t i = 0; i < vec.size()-1; i++) out << vec.at(i) << ", ";
    return out << vec.back() << ']';
}
ll INF = 2e18;
ll MOD9 = 998244353;
ll MOD1 = 1e9 + 7;

// Looks like the idea is to bfs using every monster first!
// BUT, key insight is that if a monster can reach SOME SPOT, not just the exit,
// faster than A -> that spot cannot be used by A at all!!!

// Initially, I got the insight for the exits. If monster reaches exit faster, A cannot
// I would get all the exits A can reach, and then do a bfs from those exits
// to see if any M's seen before

// However, with monster BFS method, I believe that you can prune the search
// if another monster can reach the position faster
// thus the time complexity would be much less!

vv64 paths;
// vp32 mons;
queue<pair<p32, int>> mons;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int main(){
    int n, m; cin >> n >> m;
    paths = vv64(n, v64(m, INF));
    vector<string> board(n);
    p32 st;
    for(int i = 0; i < n; i++){
        cin >> board[i];
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'A') { 
                paths[i][j] = 0;
                st = mp(i, j);
            }
            else if(board[i][j] == '#') paths[i][j] = 0; // Nothing better, don't even try to move
            else if(board[i][j] == 'M'){
                paths[i][j] = 0;
                // add monster to somewhere to bfs later
                mons.push(mp(mp(i, j), 0));
            }
        }
    }
    if(st.f == 0 || st.f == n-1 || st.s == 0 || st.s == m-1){
        cout << "YES" << endl;
        cout << 0 << endl;
        return 0;
    }

    // performing monster bfs
    while(!mons.empty()){
        // p32 bk = mons.back(); mons.pop_back();
        // queue<pair<p32, int>> q; q.push({bk, 0}); // clearing the queue every loop might be bad...
        // while(!q.empty()){
            auto fr = mons.front(); mons.pop();
            int cy = fr.f.f, cx = fr.f.s, moves = fr.s;
            for(int i = 0; i < 4; i++){
                int ny = cy + dy[i], nx = cx + dx[i];
                if(ny >= 0 && ny < n && nx >= 0 && nx < m){
                    if(moves + 1 < paths[ny][nx]){ // pretty elegant, handles wall and monster occupy case!
                                                  // actually, try to remeber this. BFS with pruning!
                        paths[ny][nx] = moves + 1;
                        mons.push(mp(mp(ny, nx), moves + 1));
                    }
                }
            }
        // }
    }

    // performing A bfs
    vector<vp32> pare(n, vp32(m));
    queue<pair<p32, int>> q; q.push(mp(st, 0));
    pare[st.f][st.s] = mp(-1, -1);
    while(!q.empty()){
        auto fr = q.front(); q.pop();
        int cy = fr.f.f, cx = fr.f.s, moves = fr.s;
        for(int i = 0; i < 4; i++){
            int ny = cy + dy[i], nx = cx + dx[i];
            if(ny >= 0 && ny < n && nx >= 0 && nx < m){
                if(moves + 1 < paths[ny][nx]){ // pretty elegant, handles wall and monster occupy case!
                                                // actually, try to remeber this. BFS with pruning!
                                                // Video I watched defined this as LAVA FLOW PROBLEM
                    paths[ny][nx] = moves + 1;
                    pare[ny][nx] = {cy, cx};
                    if(ny == 0 || ny == n - 1 || nx == 0 || nx == m - 1){
                        cout << "YES" << endl;
                        // for(int j = 0; j < n; j++){
                        //     dbg(pare[j]);
                        // }
                        // TODO:
                        vector<char> ret;
                        int curry = ny, currx = nx;
                        while(curry != -1 && currx != -1){
                            // cout << mp(curry, currx) << endl;
                            // cout << pare[curry][currx] << endl;
                            for(int k = 0; k < 4; k++){
                                if((curry + dy[k]) == pare[curry][currx].f && (currx + dx[k]) == pare[curry][currx].s){
                                    // cout << "T" << " " << pare[curry][currx] << endl;
                                    if(k == 0) ret.pb('U');
                                    else if(k == 1) ret.pb('D');
                                    else if(k == 2) ret.pb('L');
                                    else ret.pb('R');
                                    break;
                                }
                            }
                            tie(curry, currx) = pare[curry][currx];
                        }
                        cout << ret.size() << endl;
                        while(!ret.empty()){
                            cout << ret.back(); ret.pop_back();
                        }
                        cout << endl;
                        return 0;
                    }
                    q.push(mp(mp(ny, nx), moves + 1));
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}