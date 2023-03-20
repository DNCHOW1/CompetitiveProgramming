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

int seen[27]{};

int main(){
    int o = 0;
    for(int i = 0; i < 26; i++) {
        cin >> seen[i];
        o += (seen[i]%2);
    }

    if(o >= 2){ // no
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        string out;
        char mid;
        for(int i = 0; i < 26; i++){
            if(seen[i]%2){
                mid = i + 'a';
            }
            out += string(seen[i]/2, i+'a');
        }
        cout << out << mid;
        reverse(out.begin(), out.end());
        cout << out << endl;
    }
    return 0;
}