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

vv32 pos(2e5 + 1, v32());

int main(){
    int n, q; cin >> n;
    v32 a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pos[a[i]].pb(i);
    }

    cin >> q;
    while(q--){
        int l, r, x; cin >> l >> r >> x;
        l--, r--;
        int L = -1, R = -1;
        // bool f1 = false, f2 = false;

        if(pos[x].size() == 0){
            cout << 0 << endl;
            continue;
        }

        int a = 0, b = pos[x].size() - 1;
        while(a <= b){ // binary search for first index
            int mid = (b - a)/2 + a;
            if(pos[x][mid] >= l){
                L = mid;
                b = mid - 1;
            } else a = mid + 1;
        }

        a = 0, b = pos[x].size() - 1;
        while(a <= b){
            int mid = (b - a)/2 + a;
            if(pos[x][mid] <= r){
                R = mid;
                a = mid + 1;
            } else b = mid - 1;
        }

        if(L == -1 || R == -1) cout << 0 << endl;
        else cout << (R - L + 1) << endl; // because I choose <= R, I have to offset with +1
                                        // if I chose strictly > R, don't have to offset
    }
    return 0;
}