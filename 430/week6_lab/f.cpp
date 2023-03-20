#include <bits/stdc++.h>  
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

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
    ll l, w, n, r;
    cin >> l >> w >> n >> r;
    vector<bitset<4>> arr(n);
    ll mn = 1e9;
    bitset<4> temp = 0;
    vector<pair<double, double>> cent = {{-l/2.0, 0}, {l/2.0, 0}, {0, -w/2.0}, {0, w/2.0}};
    for(auto i = 0; i < n; i++){
        ll x, y; cin >> x >> y;
        for(int j = 0; j < 4; j++){
            arr[i][j] = sqrt(pow(x-cent[j].f, 2) + pow(y-cent[j].s, 2)) <= r;
        }
        temp |= arr[i];
    }
    if(temp == 0b1111) mn = 4;

    for(int i = 0; i < n; i++){
        if(arr[i] == 15) mn = 1;
        for(int j = i+1; j < n; j++){
            if((arr[i] | arr[j]) == 15) mn = min(mn, 2LL);
            for(int k = j+1; k < n; k++){
                if((arr[i] | arr[j] | arr[k]) == 15) mn = min(mn, 3LL);
            }
        }
    }

    if(mn != 1e9) cout << mn << endl;
    else cout << "Impossible" << endl;
    return 0;
}