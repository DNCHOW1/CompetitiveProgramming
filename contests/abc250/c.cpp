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

int a[200005]{};

int main(){
    int n, q; cin >> n >> q; // n and q very large
    map<int, int> m;
    for(int i = 1; i <= n; i++) { // nlogn
        a[i] = i;
        m[i] = i;
    }
    while(q--){ // qlogn
        int t; cin >> t;
        int ind = m[t];
        if(ind == n){ // swap with left, update right
            m[t] = ind-1;
            m[a[ind-1]] = ind;
            swap(a[ind-1], a[ind]);
        } else{
            m[t] = ind+1;
            m[a[ind+1]] = ind;
            swap(a[ind+1], a[ind]);
        }
    }
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}