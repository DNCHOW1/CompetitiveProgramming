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

void solve2(){
    int n; cin >> n;
    int prev = -1;
    int i = 0;
    bool flag = false;
    if(n%2){ // if odd length, then the 1st elem MUST be the 1st elem
        cin >> a[i];
        prev = a[i++];
    }
    for(; i < n; i++){ // I think this only works when array is even length
        cin >> a[i];
        if((i+(n%2))%2){
            if(min(a[i], a[i-1]) < prev){
                flag = true;
            }
            prev = max(a[i], a[i-1]);
        }
    }
    if(flag){
        cout << "NO" << endl;
    } else{
    cout << "YES" << endl;

    }
}

int main(){
    int t; cin >> t;
    while(t--){
        solve2();
    }
    return 0;
}