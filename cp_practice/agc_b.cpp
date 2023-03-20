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
    string s; cin >> s;
    int ac = 0;
    char prev = ' ';
    ll tot = 0;
    for(auto &x: s){
        if(x == 'A') {
            if(prev == 'A') ac++;
            else ac = 1;
        }
        else if(x == 'B' && prev != 'A') ac = 0;
        else if(x == 'C'){
            if(prev == 'B'){
                tot += ac;
                prev = 'A'; // override below
                continue;
            } else ac = 0;
        }
        prev = x;
    }
    cout << tot << endl;
    return 0;
}