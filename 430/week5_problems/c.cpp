#include <bits/stdc++.h>  
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

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

// parent has child at 2i and 2i + 1
v64 segments;

void flip(ll i, ll l, ll r, ll pos){
    if(l == r) segments[i] = !segments[i];
    else{
        ll mid = (l + r)/2;
        if(pos <= mid) flip(2*i, l, mid, pos);
        else flip(2*i+1, mid+1, r, pos);
        segments[i] = segments[2*i] + segments[2*i+1];
    }
}

ll query(ll i, ll l, ll r, ll L, ll R){
    if(l > r) return 0; // Only do this when we're out of range
    else if(l == L && r == R) return segments[i];
    ll mid = (L+R)/2;
    return query(i*2, l, min(r, mid), L, mid) + query(i*2+1, max(l, mid+1), r, mid+1, R);
}

int main(){
    ll N, K; cin >> N >> K;
    segments = v64(N*4+5, 0); // have extra padding just in case
    while(K--){
        char op;
        cin >> op;
        if(op == 'F'){
            ll i; cin >> i;
            flip(1, 1, N, i);
        } else{
            ll l, r;
            cin >> l >> r;
            cout << query(1, l, r, 1, N) << endl;
        }
    }
    return 0;
}