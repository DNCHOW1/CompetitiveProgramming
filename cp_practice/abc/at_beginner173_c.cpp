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
 
vector<string> grid;
int row[6]{};
int col[6]{};

int h, w, k;

int totalsK(){
    int count = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(!row[i] && !col[j]) count += (grid[i][j] == '#');
        }
    }
    return count;
}

int main(){
    cin >> h >> w >> k;
    
    for(int i = 0; i < h; i++){
        string temp; cin >> temp;
        grid.push_back(temp);
    }

    int tot = h + w; // total length of the bit mask
    long long total = 0;
    for(int i = 0; i < (1 << tot); i++){ // _ _ _ _ _ | _ _ _ ... _ represents which rows blocked and cols blocked
        int count = 0;
        for(int r = 0; r < h; r++){
            for(int c = 0; c < w; c++){
                bool cond = !(i & (1 << (r + w))) && (i & (1 << c));
                if(cond){
                    count += (grid[r][c] == '#');
                }
            }
        }
        total += (count == k);
    }
    cout << total << endl;
    return 0;
}