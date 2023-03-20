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

// count # of 1s seen = A
// count # of ?s seen = B
// # of 1s seen(A) * # of strings w/ those 1s 2^B
// + # of 1s among possible ?s (K(B) = B*2^(B-1))

// Reflections:
// Silly mod mistake, used the mult2mod function when I meant to mult two numbers, NOT multiplying by 2
// Coming up with algorithm was a bit slow, but figured out counting method
// Keeping a ON vector redundant, can just keep variable keeping track of set bits
// Should have derived that # of on bits for # of ?s is = B*2^(B-1)

v64 TWO = {1, 2};
v64 ON = {0, 1};

ll mult2mod(ll num){
    return (num << 1)%MOD1;
}

// inversion function
ll inversion(ll ones, ll q){
    if(TWO.size() == q) {
        ON.pb( (mult2mod(ON.back()) + TWO.back())%MOD1 );
        TWO.pb(mult2mod(TWO.back()));
    }
    return ((ones*TWO[q])%MOD1 + ON[q])%MOD1;
}

int main(){
    ll tot = 0, ones = 0, qs = 0;
    string S; cin >> S; // length is [1, 1e5 * 5]
    for(auto c: S){
        if(c == '1') ones++;
        else if(c == '0'){
            tot = (tot + inversion(ones, qs))%MOD1;
        }
        else{
            // ? = 1
            // multiply by 2, because we will count case when 1 AND case when 0
            tot = mult2mod(tot);

            // ? = 0
            tot = (tot + inversion(ones, qs))%MOD1;
            qs++;
        }
    }
    cout << tot << endl;
    return 0;
}