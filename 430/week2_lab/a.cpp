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



int main(){
    int board[4][4] = {};
    int newB[4][4] = {};

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) cin >> board[i][j];
    }

    int dir; cin >> dir;
    v32 temp;
    v32 out;
    if(dir == 0){
        for(int i = 0; i < 4; i++){
            bool cond = false;
            for(int j = 0; j < 4; j++){
                if(board[i][j] != 0) {
                    if(temp.size() != 0 && temp.back() == board[i][j] && cond) {
                        temp[temp.size() - 1] = (board[i][j] * 2);
                        cond = false;
                    }
                    else{
                        temp.pb(board[i][j]);
                        cond = true;
                    }
                }
            }
            for(int j = 0; j < 4; j++){
                if(j < temp.size()) board[i][j] = temp[j];
                else board[i][j] = 0;
            }
            temp.clear();
        }
    } else if (dir == 1){
        for(int j = 0; j < 4; j++){
            bool cond = false;
            for(int i = 0; i < 4; i++){
                if(board[i][j] != 0) {
                    if(temp.size() != 0 && temp.back() == board[i][j] && cond) {
                        temp[temp.size() - 1] = (board[i][j] * 2);
                        cond = false;
                    }
                    else{
                        temp.pb(board[i][j]);
                        cond = true;
                    }
                }
            }
            for(int i = 0; i < 4; i++){
                if(i < temp.size()) board[i][j] = temp[i];
                else board[i][j] = 0;
            }
            temp.clear();
        }
    } else if (dir == 2) {
        for(int i = 0; i < 4; i++){
            bool cond = false;
            for(int j = 3; j >= 0; j--){
                if(board[i][j] != 0) {
                    if(temp.size() != 0 && temp.back() == board[i][j] && cond) {
                        temp[temp.size() - 1] = (board[i][j] * 2);
                        cond = false;
                    }
                    else{
                        temp.pb(board[i][j]);
                        cond = true;
                    }
                }
            }
            // cout << temp << endl;
            for(int j = 0; j < 4; j++){
                if(j < temp.size()) board[i][4-j-1] = temp[j];
                else board[i][4-j-1] = 0;
            }
            temp.clear();
        }
    } else{
        for(int j = 0; j < 4; j++){
            bool cond = false;
            for(int i = 3; i >= 0; i--){
                if(board[i][j] != 0) {
                    if(temp.size() != 0 && temp.back() == board[i][j] && cond) {
                        temp[temp.size() - 1] = (board[i][j] * 2);
                        cond = false;
                    }
                    else{
                        temp.pb(board[i][j]);
                        cond = true;
                    }
                }
            }
            // cout << temp << endl;
            for(int i = 0; i < 4; i++){
                if(i < temp.size()) board[4-i-1][j] = temp[i];
                else board[3-i][j] = 0;
            }
            temp.clear();
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) cout << board[i][j] << " ";
        cout << endl;
    }
    return 0;
}