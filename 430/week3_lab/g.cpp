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
    ll x;
    map<ll, ll> powers;
    for(ll i = -70000; i <= 70000; i++){
        if(abs(i) < 2) continue;
        ll num = i*i;
        if(num <= INT32_MAX){
            ll cnt = 2;
            while(num <= INT32_MAX){
                powers[num] = max(powers[num], cnt);
                num *= i;
                cnt++;
            }
            powers[num] = max(powers[num], cnt);
        }
    }

    while(cin >> x){
        if(x == 0) break;
        if(powers.count(x) == 0) cout << 1 << endl;
        else cout << powers[x] << endl;
    }
    return 0;
}