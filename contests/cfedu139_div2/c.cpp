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
    int t; cin >> t;
    vector<string> wall = vector<string>(2);
    while(t--){
        int n; cin >> n;
        cin >> wall[0];
        cin >> wall[1];
        bool prevA = true, prevB = true;

        for(int i = 0; i < n; i++){
            bool temp;
            if(wall[0][i] == 'B' && wall[1][i] == 'B'){
                temp = prevB;
                prevB = prevA;
                prevA = temp;
            } else{
                prevA &= (wall[0][i] == 'B');
                prevB &= (wall[1][i] == 'B');
            }
        }

        if(prevA || prevB) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}