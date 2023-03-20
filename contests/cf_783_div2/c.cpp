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
    int n; cin >> n;
    v64 a(n);
    for(auto &x: a) cin >> x;

    ll opCount = INF;
    for(int i = 0; i < n; i++){
        ll tempC = 0;

        // pretend we have b[i] set to 0
        ll prev = 0;
        
        // iterate backwards, making sure it decreases continually
        // if you flip your thinking, you need to make sure its magnitude increases continually
        // -5, 3
        for(int j = i - 1; j >= 0; j--){
            ll amt = prev/a[j] - 1;
            tempC += abs(amt);
            prev = a[j]*amt;
        }

        // iterate forwards, making sure it increases continually
        prev = 0;
        for(int j = i + 1; j < n; j++){
            ll amt = prev/a[j] + 1;
            tempC += amt;
            prev = a[j]*amt;
        }

        opCount = min(tempC, opCount);
    }
    cout << opCount << endl;
    return 0;
}