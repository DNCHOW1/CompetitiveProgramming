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

// Reflections
// Made the wrong analysis that there must be n holes for a valid cipher. This misunderstanding heavily hurt
//  think more next time, and try another test case! With n = 4 I got the wrong idea
//  Trying to be smart by accessing 1D string with (n*i + j) was incorrect, MUST use (pow(n, 2)*i/4 + j)
// Had trouble thinking about how to rotate (r, c) -> stuck in dead end thinking about modulos
//  Solution: Break down the cases one by one. If I had done this, would've realized that...
//      0th index maps to last index
//      1st index maps to second last index
//      etc...
//   It's just a simple n-1-i!
// Although using multiset to keep everything in order was a decent idea, NEED to think even simpler
//  By using rotating the matrix normally could've saved some time thinking, maybe???

int main(){
    
    int n; cin >> n;
    ll cnt = pow(n, 2);
    vector<string> mat(n);
    multiset<p64> pos;
    string encrypt;
    vector<vector<char>> decrypted(n, vector<char>(n, '*'));

    for(int i = 0; i < n; i++) cin >> mat[i];
    cin >> encrypt;

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            if(mat[i][j] == '.') pos.insert({i, j});
        }
    }

    bool flag = cnt/4 != pos.size();
    dbg(flag);
    for(int i = 0; i < 4; i++){ // all the rotations
        multiset<p64> temp;
        int j = 0;
        for(auto& [r, c]: pos){
            // cout << r << " " << c << endl;
            if(decrypted[r][c] != '*') {
                flag = true;
                break;
            }
            decrypted[r][c] = encrypt[(pow(n, 2)*i/4 + j)];
            temp.insert({c, n-1-r});
            j++;
            cnt--;
        }
        pos = move(temp);
    }

    // dbg(cnt);
    if(flag || cnt != 0) cout << "invalid grille";
    else{
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(decrypted[i][j] == '*') return 1;
                cout << decrypted[i][j];
            }
        }
    }
    cout << endl;
    return 0;
}