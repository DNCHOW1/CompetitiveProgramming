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
* Overthinking the problem, just brute force when unsure
* Read problem statement more carefully, and think a bit more(don't worry too much about speed)
*/

int main(){
    int n, m; cin >> n >> m;
    ll counts[41] = {};
    ll mx = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            counts[i+j]++;
            mx = max(mx, counts[i+j]);
        }
    }

    for(int i = 1; i <= 40; i++){
        if(counts[i] == mx){
            cout << i << endl;
        }
    }
    return 0;
}