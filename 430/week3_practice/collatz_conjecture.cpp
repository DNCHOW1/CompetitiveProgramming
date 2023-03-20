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

// Reflection
// Didn't test out where one of the numbers is 1
// when while loop ends if you want something to happen to the last number MAKE SURE TO DO IT

unordered_map<ll, ll> M;

p64 collatz(ll num){
    ll steps = 0;
    while(num != 1 && M.count(num) == 0){
        M[num] = steps;
        if((num & 1)) num = num*3 + 1;
        else num >>= 1;
        steps++;
    }
    if(M.count(1) == 0) M[1] = steps;
    return mp(num, steps);
}

int main(){
    // At most 1500 test cases
    // A B <= 1e6
    // if 2 0s then stop
    // collatz in worst case is 524 steps
    ll a, b;
    while(cin >> a >> b){
        if(a == 0 || b == 0) break;
        collatz(a);
        auto [end, steps] = collatz(b);
        printf("%lld needs %lld steps, %lld needs %lld steps, they meet at %lld\n", a, M[end], b, steps, end);
        M.clear();
    }

    return 0;
}