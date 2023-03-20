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
    v64 squares;
    for(int i = 1; i <= n; i++) squares.pb(i*i);
    cout << squares << endl;

    ll tot = 0;
    for(ll i = 1; i < sqrt(n) + 1; i++){
        int l = 0, r = squares.size() - 1;
        // with this binary search, find the index of the highest square*i that is <= N
        while(l < r){
            int mid = (r-l+1)/2 + l;
            if(squares[mid]*i > n)
                r = mid-1;
            else
                l = mid;
        }
        printf("%lld %lld\n", i, l);
        tot += (2*l - 1);
    }
    cout << tot << endl;
    return 0;
}