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

int add(int i, int j, int k){
    int temp = 0;
    temp = (i+j)%MOD1;
    return (temp+k)%MOD1;
}

int add(int& i, int j){
    if((i += j) >= MOD1){
        i -= MOD1;
    }
    return i;
}

const int mx = 2e3 + 5;
int qn[mx][mx]{};
int horz[mx][mx]{};
int vert[mx][mx]{};
int diag[mx][mx]{};

int main(){
    int h, w;
    cin >> h >> w;
    qn[1][1] = horz[1][1] = vert[1][1] = diag[1][1] = 1;
    vector<string> input;
    for(int i = 0; i < h; i++){
        string temp; cin >> temp;
        input.push_back(temp);
    }

    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(input[i-1][j-1] != '#' && (i != 1 || j != 1)){
                qn[i][j] = horz[i][j] = vert[i][j] = diag[i][j] = add(horz[i][j-1], vert[i-1][j], diag[i-1][j-1]);
                // affect the respective position's horz, vert, and diag
                add(horz[i][j], horz[i][j-1]);
                add(vert[i][j], vert[i-1][j]);
                add(diag[i][j], diag[i-1][j-1]);
            }
        }
    }
    
    cout << qn[h][w] << endl;
    return 0;
}