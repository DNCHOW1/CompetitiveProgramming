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

int a[100005]{};

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int l = 0, r = n - 1;
    while(l < r){
        if(a[l] >= a[l + 1] && a[l] > 0){ // Did > than for comparison initially, fixed but still fails pretest 2
            if(a[r] < 0){
                a[l++] *= -1;
                a[r--] *= -1;
            } else{
                r--;
            }
        } else{ // If already ascending OR a[l] negative(in which case can't flip)
            l++;
        }
    }

    // for(int i = 0; i < n; i++) cout << a[i] << " ";
    // cout << endl;

    bool flag = false;
    for(int i = 1; i < n; i++){
        flag = flag || a[i] < a[i-1];
    }

    if(flag){
        cout << "NO" << endl;
    } else{
        cout << "YES" << endl;
    }
}

int main(){
    int t; cin >> t;
    while(t--) solve();
    return 0;
}