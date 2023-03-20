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
    // The reason the formula n*(n-1)/2 is used is because this represents n Combinations choose 2(because pairs of 2)
    // Its combinations because the order of the groups doesn't matter

    int n, m; cin >> n >> m; // # of parts, # of teams
    // max is trivial to calculate: a = (n - m + 1); max = (a * (a-1)/2)

    // min however...
    // group_size = n / m (which floors down the result)
    // if n%m == 0: m*(group_size * (group_size - 1)/2)
    // else: (m-1)(group_size * (group_size-1)/2) + (group_size * (group_size + 1)/2)

    ll a = (n - m + 1), mx = (a * (a - 1)/2);
    ll mn, g = n/m;
    if(n % m == 0) mn = m*(g * (g - 1)/2);
    else{
        ll rem = n % m;
        mn = (m-rem)*(g * (g-1)/2) + rem*(g*(g+1)/2);
    }
    cout << mn << " " << mx << endl;
    return 0;
}