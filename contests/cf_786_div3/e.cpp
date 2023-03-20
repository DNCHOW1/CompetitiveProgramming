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
    int n; cin >> n;
    v64 a(n);
    p64 m2 = {INF, -1}, m1 = {INF, -1};
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a[i] = x;
        if(x < m1.f){
            m2 = m1;
            m1 = mp(x, i);
        } else if(x < m2.f){
            m2 = mp(x, i);
        }
    }

    ll mx = ceil(m1.f/2.0) + ceil(m2.f/2.0);
    for(int i = 0; i < n; i++){

        // Would only do the below if x < 2y. Else, one wall would break before we equalize
        if(i != 0) { // Check if decreasing left
            if(a[i] >= 2*a[i-1] || a[i-1] >= 2*a[i])
                mx = min(mx, (ll)ceil(max(a[i], a[i-1])/2.0));
            else
                mx = min(mx, (ll)ceil((a[i] + a[i-1])/3.0));
        }
        if(i != n-1){
            if(a[i] >= 2*a[i+1] || a[i+1] >= 2*a[i])
                mx = min(mx, (ll)ceil(max(a[i], a[i+1])/2.0));
            else
                mx = min(mx, (ll)ceil((a[i] + a[i+1])/3.0));
        }
        // Check for the adjacent, max of the two
        if(i != n - 1 && i != 0){
            ll mn = min(a[i-1], a[i+1]);
            mx = min(mx, mn + (ll)ceil(max(a[i-1]-mn, a[i+1]-mn)/2.0));
        }
    }
    cout << mx << endl;
    return 0;
}