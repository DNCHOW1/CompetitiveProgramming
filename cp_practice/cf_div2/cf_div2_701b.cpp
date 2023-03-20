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
    int n, q, k; cin >> n >> q >> k;
    v32 a(n);
    for(auto &x: a) {
        cin >> x;
    }

    v64 L(n), R(n);
    for(int i = 0; i < n; i++){
        if(i == 0){
            L[i] = a[i] - 1;
        } else{
            L[i] = a[i] - a[i-1] - 1;
        }
        if(i == n -1){
            R[i] = k - a[i];
        } else{
            R[i] = a[i+1] - a[i] - 1;
        }
    }
    v64 preL(n + 1), preR(n + 1);
    for(int i = 1; i <= n; i++){ // building prefix sum
        preL[i] += L[i-1] + preL[i-1];
        preR[i] += R[i-1] + preR[i-1];
    }

    // dbg(preL);
    // dbg(preR);
    while(q--){
        int l, r; cin >> l >> r;
        // cout << a[l - 1] - 1 << " " << k - a[r-1] << endl;
        cout << (a[l - 1] - 1 + k - a[r-1] + (preL[r] - preL[l]) + (preR[r-1] - preR[l-1])) << endl;
    }
    return 0;
}