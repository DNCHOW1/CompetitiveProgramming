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



int main(){
    ll n; cin >> n;
    map<ll, set<ll>> mapping;
    vv64 mat;
    vv64 out;
    vector<set<ll>> used(n+1);
    for(ll i = 1; i <= n; i++){
        ll m; cin >> m;
        v64 arr(m);
        for(ll j = 0; j < m; j++){
            ll num; cin >> num;
            mapping[num].insert(i);
            used[i].insert(num);
        }
        mat.pb(arr);
    }

    for(ll i = 1; i <= n; i++){
        for(auto num: mat[i-1]){
            if(used[i].count(num) == 1){
                
            }
        }
    }

    for(ll i = 1; i <= n; i++){
        bool flag = false;
        for(auto num: mat[i-1]){
            if(mapping[num].size() > 1){
                for(auto num2: mapping[num]){
                    if(num2 != num){
                        flag = true;
                        out.pb({i, num2, num});
                        mapping[num].erase(i);
                        break;
                    }
                }
            }
            if(flag) break;
        }
    }


    return 0;
}