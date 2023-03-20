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

vector<string> ar(4);

bool squareH(int a, int b){
    int cnt = 0;
    for(int i = 0; i < 2; i++){
        if(a + i >= 4) break;
        for(int j = 0; j < 2; j++){
            if(b + j >= 4) break;
            if(ar[a + i][b + j] == '#') cnt++;
        }
    }
    return cnt >= 3;
}

bool squareD(int a, int b){
    int cnt = 0;
    for(int i = 0; i < 2; i++){
        if(a + i >= 4) break;
        for(int j = 0; j < 2; j++){
            if(b + j >= 4) break;
            if(ar[a + i][b + j] == '.') cnt++;
        }
    }
    return cnt >= 3;
}

int main(){
    for(auto &x: ar) cin >> x;

    // check initially for squares
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(squareH(i, j) || squareD(i, j)){
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}