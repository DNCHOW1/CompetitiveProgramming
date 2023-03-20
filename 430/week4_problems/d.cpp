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
// Understanding of the problem was completely off
// Foreign ingredient and native ingredient are a bijective mapping
//  i.e. native ingredient MUST be in set if foreign ingredient appears
//       and foreign ingredient MUST be in set if native ingredient appears

void set_intersection(set<string>& a, set<string>& b){
    set<string> new_set;
    for(auto ingre: a){
        if(b.count(ingre) == 1) new_set.insert(ingre);
    }
    a = move(new_set);
}

void solve() {
    ll n; cin >> n;
    map<string, set<string>> foreign_set;
    map<string, set<string>> native_set;
    for(ll i = 0; i < n; i++){
        string s;
        set<string> foreign;
        set<string> native;
        int n;
        cin >> s; // Read in pizza name
        
        cin >> n;
        while(n--){
            cin >> s;
            foreign.insert(s);
        }
        cin >> n;
        while(n--){
            cin >> s;
            native.insert(s);
        }

        for(string fore: foreign){
            if(foreign_set.count(fore) == 0){ // Prone to error
                foreign_set[fore] = native;
            } else{
                set_intersection(foreign_set[fore], native);
            }
        }
        for(string nat: native){
            if(native_set.count(nat) == 0){
                native_set[nat] = foreign;
            } else{
                set_intersection(native_set[nat], foreign);
            }
        }
    }

    for(auto& [fore, nat_set]: foreign_set){
        for(string nat: nat_set){
            if(native_set[nat].count(fore) == 1) printf("(%s, %s)\n", fore.c_str(), nat.c_str());
        }
    }
    
}

int main(){
    ll t; cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
    return 0;
}