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

// Reflections:
// Looked at solution early, should've thought more ):
// Had the intuition that stuff to left of removed should be counted, while stuff to right shouldn't be
//  HOWEVER - got stuck on the idea of updating everything on the left by incrementing by 1.
// Idea of m+r is smart, imagining bits that are simply moved in some array is clean


// we'll want to remove it from old pos and move it to new pos
void update(v64& segs, ll val, ll i, ll left, ll right, ll pos){
    if(left == right){
        segs[i] = val;
    } else{
        ll mid = (left + right)/2;
        if(pos <= mid) update(segs, val, 2*i, left, mid, pos);
        else update(segs, val, 2*i+1, mid+1, right, pos);
        segs[i] = segs[2*i] + segs[2*i+1];
    }
}

ll sums(v64& segs, ll i, ll left, ll right, ll L, ll R){
    if(left > right) return 0;
    else if(left == L && right == R) return segs[i];
    ll mid = (L + R)/2;
    return sums(segs, 2*i, left, min(right, mid), L, mid) + sums(segs, 2*i+1, max(mid+1, left), right, mid + 1, R);
}

void solve(){
    ll m, r; cin >> m >> r;
    v64 segments(4*(m+r)+5);
    v64 indices(m+r+5);

    // build the thingy
    // 1 at pos m
    for(ll i = 1; i <= m; i++){
        indices[i] = m+1-i;
        update(segments, 1, 1, 1, m+r, indices[i]);
    }

    // process the r and print out each
    for(int i = 0; i < r; i++) {
        ll num; cin >> num;
        cout << sums(segments, 1, indices[num] + 1, m+r, 1, m+r) << " ";
        update(segments, 0, 1, 1, m+r, indices[num]);
        indices[num] = m+i+1;
        update(segments, 1, 1, 1, m+r, indices[num]);
    }
    cout << endl;
}

int main(){
    ll t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}