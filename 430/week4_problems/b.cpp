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

struct DSU{
    map<string, string> dsu;
    map<string, ll> sizes;

    string get(string x) { 
        if(dsu.count(x) == 0){
            dsu[x] = x;
            sizes[x] = 1;
        }
        return (x == dsu[x]) ? x : dsu[x] = get(dsu[x]); 
    }

    ll unite(string x, string y){
        string a = get(x), b = get(y);
        if(a == b) return sizes[a];
        dsu[b] = a;
        sizes[a] += sizes[b];
        return sizes[a];
    }
};

int main(){
    // n - <= 100000
    ll n; cin >> n;
    DSU dsu;
    for(ll i = 0; i < n; i++){
        string a, b; cin >> a >> b;
        cout << dsu.unite(a, b) << endl;
    }
    return 0;
}