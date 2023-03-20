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

/*
* Should initialize a vector<char> with something just to be safe
* Adil said that ceil(sqrt(l)) could lead to floating point errors, be careful
* Should probably jsut use a vector of strings instead of vector<vector<char>>?
*/

void solve(string in) {
    int l = in.size();
    int k = ceil(sqrt(l));
    vector<vector<char>> repr = vector<vector<char>>(k, vector<char>(k, '&'));
    for(int i = 0; i < l; i++){
        repr[i/k][i%k] = in[i];
    }

    for(int i = 0; i < k; i++){
        for(int j = k -1; j >= 0; j--){
            if(repr[j][i] != '&') cout << repr[j][i];
        }
    }
}

int main(){
    int n; cin >> n;
    while(n--){
        string in; cin >> in;
        solve(in);
        cout << endl;
    }
    return 0;
}