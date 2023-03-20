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

bool sieve[1000005]{};
v64 primes;

int main(){
    ll n; cin >> n; // can be as high as 1e18
    for (int x = 2; x <= 1000000; x++) { // runs in nlogn time
        if (sieve[x]) continue;
        for (int u = 2*x; u <= 1000000; u += x) {
            sieve[u] = true;
        }
    }

    for(int i = 2; i <= 1000000; i++) {
        if(!sieve[i]) 
            primes.pb(i);
    }

    ll ans = 0;
    for(int p = 0; p < primes.size(); p++){
        // binary search the primes array
        int l = 1, r = primes.size() - 1;
        while(l < r){
            ll mid = (r + l)/2 + 1;
            // cout << l << " " << r << " " << mid << endl;
            if(primes[p]*pow(primes[mid], 3LL) <= n){
                l = mid;
            } else{
                r = mid - 1;
            }
        }
        if(primes[p] < primes[l] && primes[p]*pow(primes[l], 3LL) <= n){
            // printf("%lld %lld %lld\n", primes[p], primes[l], l);
            ans += (l - p); // the adding is bad
        }
    }
    cout << ans << endl;
    return 0;
}