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

// Reflection:
// mn could be set to n instead

int main(){
    ll n; cin >> n;
    v64 arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());
    // 1 2 2 3 8 8
    // 0 1 2 3 4 5
    // 3 gets rid of good chunk, + 2 for mn

    // arr holds block heights
    // destroy all using arr[i], then delete remaining i

    // after getting rid of arr[i], remaining arr[n-1]-arr[i] might be good
    // 1 1 3 3 3 3 3 3
    // 0 0 2 2 2 2 2 2
    // 1 1 3 3
    // 1 1 1 1 1
    // 1 1 1 1 5 5 5 5 8 8
    // 1 1 1 1 5 5 5 5 6 6
    // 0 0 0 0 0 0 0 0 3 3
    // 5 5 5
    ll mn = 1e9;
    for(int i = 0; i < n; i++){
        mn = min(mn, arr[i] + n - i - 1);
    }
    cout << min(mn, n) << endl;
    return 0;
}