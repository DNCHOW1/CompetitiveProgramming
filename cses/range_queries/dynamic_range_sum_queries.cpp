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

ll n;
v32 arr;
v64 segments;

void build(ll i, ll l, ll r){
    // if(i >= 2*n) cout << i << " " << l << " " << r << endl;
    if(l == r) {
        segments[i] = arr[l-1];
    } else{
        ll mid = (l+r)/2;
        build(2*i, l, mid);
        build(2*i + 1, mid+1, r);
        segments[i] = segments[2*i] + segments[2*i+1];
    }
}

void update(ll i, ll l, ll r, ll pos, ll val){
    if(l == r) {
        segments[i] = val;
    }
    else{
        ll mid = (l+r)/2;
        if(pos <= mid) update(2*i, l, mid, pos, val);
        else update(2*i+1, mid+1, r, pos, val);
        segments[i] = segments[2*i] + segments[2*i+1];
    }
}

ll sums(ll i, ll l, ll r, ll L, ll R){
    if(l > r) return 0;
    else if(l == L && r == R) return segments[i];
    ll mid = (L + R)/2;
    return sums(2*i, l, min(mid, r), L, mid) + sums(2*i+1, max(mid+1, l), r, mid+1, R);
}

int main(){
    ll q; cin >> n >> q;
    arr = v32(n);
    segments = v64(4*n+5);
    for(int i = 0; i < n; i++) cin >> arr[i];
    build(1, 1, n);
    while(q--){
        ll op, a, b;
        cin >> op >> a >> b;
        if(op == 1){
            update(1, 1, n, a, b);
        } else{
            cout << sums(1, a, b, 1, n) << endl;
        }
        // dbg(segments);
    }
    return 0;
}