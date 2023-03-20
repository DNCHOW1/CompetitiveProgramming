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

int P[7] = {};
vv64 segments;
string in;

void build(ll val, ll i, ll left, ll right, ll pos){
    if(left == right){
        segments[i][val] = 1;
    } else{
        ll mid = (left + right)/2;
        if(pos <= mid) build(val, 2*i, left, mid, pos);
        else build(val, 2*i+1, mid+1, right, pos);
        
        for(int j = 1; j < 7; j++){
            segments[i][j] = (segments[2*i][j] + segments[2*i+1][j]);
        }
    }
}

void replace(ll i, ll gem, ll left, ll right, ll pos){
    if(left == right){
        for(auto& num: segments[i]) num = 0;
        segments[i][gem] = 1;
    } else{
        ll mid = (left + right)/2;
        if(pos <= mid) replace(2*i, gem, left, mid, pos);
        else replace(2*i+1, gem, mid+1, right, pos);

        for(int j = 1; j < 7; j++){
            segments[i][j] = segments[2*i][j] + segments[2*i+1][j];
        }
    }
}

void get_sum(v64& a, ll pos, ll left, ll right, ll L, ll R){
    if(left > right) return;
    else if(left == L && right == R){
        for(int i = 1; i < 7; i++) a[i] += segments[pos][i];
    } else{
        ll mid = (L + R)/2;
        get_sum(a, 2*pos, left, min(right, mid), L, mid);
        get_sum(a, 2*pos+1, max(left, mid+1), right, mid + 1, R);
    }
}

int main(){
    ll n, q;
    cin >> n >> q;
    for(int i = 1; i <= 6; i++){
        cin >> P[i];
    }
    segments = vv64(4*n+5, v64(7));

    cin >> in;
    for(int i = 1; i <= n; i++){
        build(in.at(i-1) - '0', 1, 1, n, i);
    }

    while(q--){
        ll a, b, c; cin >> a >> b >> c;
        if(a == 1){
            replace(1, c, 1, n, b);
        } else if(a == 2){
            P[b] = c;
        } else{
            ll sm = 0;
            v64 temp(7);
            get_sum(temp, 1, b, c, 1, n);
            for(int i = 1; i < 7; i++){
                sm += P[i]*temp[i];
            }
            cout << sm << endl;
        }
    }
    return 0;
}