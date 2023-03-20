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
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define dbg2(x, y) cerr<< x << " " << y << endl

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
    // Problem heavily relies on modulo property where you're really trying to find subarrays where modulo res is 0
    // HOWEVER, you can also achieve modulo res 0 using subtraction property: (x - y)modm == (xmodm - ymodm)modm
    int n; cin >> n;
    v32 a(n);
    ll psum = 0;
    v64 moda(n);
    moda[0] = 1; // for some reason, this needs to be initialized to 1
                // actually... it's because if any elem == 0, it is the one exception that should immediately add
                // to the answer. Thus, it should be initialized to 1
    for(auto &x: a){
        cin >> x;
        psum += x;
        moda[(psum%n + n) % n]++; // Originally, I kind of just ignored the negative numbers
                                // although I did realize that if I added N to them, they would be n - orignal_mod
                                // However, editorial just took care like this so it's nicer
    }

    ll ans = 0;
    for(auto &x: moda){
        if(x >= 2) ans += (x * (x - 1)/2);
    }
    // dbg(moda);
    cout << ans << endl;

    // int n; cin >> n;
    // v32 a;
    // v64 pre(n + 1);
    // map<ll, ll> m;
    // ll ans = 0;

    // // Does it count 0 as divisible by n?
    // for(int i = 0; i < n; i++){
    //     int temp; cin >> temp;
    //     a.push_back(temp);
    //     pre[i+1] = a[i] + pre[i];
        
    //     ll mod = (pre[i+1]%n + n)%n;
    //     ans += m[mod];
    //     ans += (pre[i+1]%n == 0);
    //     m[mod]++;
    // }
    // cout << ans << endl;
    return 0;
}