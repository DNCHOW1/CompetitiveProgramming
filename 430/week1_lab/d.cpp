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
* READ THE PROBLEM STATEMENT MORE CAREFULLY
* READ THE PROBLEM STATEMENT MORE CAREFULLY
* READ THE PROBLEM STATEMENT MORE CAREFULLY
*/

int main(){
    int n, b, h, w; cin >> n >> b >> h >> w;
    vector<pair<int, v32>> weeks = vector<pair<int, v32>>(h);

    for(int i = 0; i < h; i++){
        int p; cin >> p;
        v32 caps;
        for(int j = 0; j < w; j++){
            int c; cin >> c;
            caps.pb(c);
        }
        weeks.pb({p, caps});
    }

    sort(weeks.begin(), weeks.end());

    for(auto [price, caps]: weeks){
        for(int cap: caps){
            if(n <= cap && n*price <= b){
                cout << n*price << endl;
                return 0;
            }
        }
    }

    cout << "stay home" << endl;

    // cout << prices << endl;
    // cout << hotels << endl;
    return 0;
}