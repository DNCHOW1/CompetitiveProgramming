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
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define f first
#define s second
#define INF 2e18
ll MOD9 = 998244353;
ll MOD1 = 1e9 + 7;
 

int main(){
    int n, sx, sy, fx, fy;
    cin >> n >> sx >> sy >> fx >> fy;
    sx--; sy--; fx--; fy--;
    vector<string> b(n);
    vector<vector<vector<int>>> d(n, vector<vector<int>>(n, vector<int>(4, 1e9))); // 4 for every field because it
                                                                                   // represents the different
                                                                                   // directions can come from
    for(auto &x: b) cin >> x;

    int dirX[4] = {1, 1, -1, -1};
    int dirY[4] = {1, -1, 1, -1};
    deque<pair<p32, int>> q;
    for(int i = 0; i < 4; i++){
        int cx = sx + dirX[i], cy = sy + dirY[i];
        if(cx < 0 || cx >= n || cy < 0 || cy >= n) continue;
        if(b[cx][cy] == '#') continue;
        // cout << cx << " " << cy << endl;
        d[cx][cy][i] = 1;
        q.push_back({{cx, cy}, i});
    }
    d[sx][sy] = {0, 0, 0, 0};
    cout << endl;
    while(!q.empty()){
        auto ab = q.front(); q.pop_front();
        int px = ab.first.first, py = ab.first.second, dir = ab.second;
        // cout << px << " " << py << endl;
        for(int i = 0; i < 4; i++){
            int cx = px + dirX[i], cy = py + dirY[i];
            // cout << cx << " " << cy << endl;
            if(cx < 0 || cx >= n || cy < 0 || cy >= n) continue;
            if(b[cx][cy] == '#') continue;
            int nd = d[px][py][dir] + (i != dir);
            if(nd >= d[cx][cy][i]) continue;
            d[cx][cy][i] = nd;

            if(i == dir) q.push_front({{cx, cy}, i});
            else q.push_back({{cx, cy}, i});
        }
    }

    int ans = 1e9 + 1;
    for(auto &x: d[fx][fy]) {
        ans = min(ans, x);
    }
    if(ans == 1e9) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}