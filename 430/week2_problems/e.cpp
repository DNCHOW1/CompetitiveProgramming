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
    int x = 0, y = 0;
    int mnX = 0, mxX = 0, mnY = 0, mxY = 0;
    string line;
    vector<string> lines;
    while(cin >> line){
        if(cin.eof()) break;

        if(line == "down"){
            y--;
            mnY = min(mnY, y);
            mxY = max(mxY, y);
        } else if(line == "up"){
            y++;
            mnY = min(mnY, y);
            mxY = max(mxY, y);
        } else if(line == "right"){
            x++;
            mnX = min(mnX, x);
            mxX = max(mxX, x);
        } else{
            x--;
            mnX = min(mnX, x);
            mxX = max(mxX, x);
        }
        lines.pb(line);
    }

    vector<vector<char>> mat = vector<vector<char>>(mxY - mnY + 1, vector<char>(mxX - mnX + 1, ' '));
    int cx = abs(mnX), cy = mxY;
    mat[cy][cx] = 'S';
    for(string line: lines){
        if(line == "down") cy++;
        else if(line == "up") cy--;
        else if(line == "right") cx++;
        else cx--;

        if(mat[cy][cx] == ' ') mat[cy][cx] = '*';
    }
    mat[cy][cx] = 'E';

    cout << string(mxX - mnX + 3, '#') << endl;
    for(auto row: mat){
        cout << '#';
        for(char c: row) cout << c;
        cout << '#';
        cout << endl;
    }
    cout << string(mxX - mnX + 3, '#') << endl;
    // printf("%d %d %d %d\n", mnX, mnY, mxX, mxY);
    // cout << x << " " << y << endl;
    return 0;
}