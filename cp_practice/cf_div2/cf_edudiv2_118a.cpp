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

char solve(){
    ll a, p, b, q;
    cin >> a >> p >> b >> q;

    ll n = a, m = b;
    int dig1 = 0, dig2 = 0;
    while(n != 0) { n/=10; dig1++; }
    while(m != 0) { m/=10; dig2++; }
    if(dig1 + p > dig2 + q) return '>';
    else if(dig1 + p < dig2 + q) return '<';
    else{
        a = a*pow(10, 13-dig1);
        b = b*pow(10, 13-dig2);
        if(a > b) return '>';
        else if(a < b) return '<';
        else return '=';
    }
}

int main(){
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        cout << solve() << endl;
    }
    return 0;
}