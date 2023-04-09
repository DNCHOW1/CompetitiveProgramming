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
    v64 arr(26);
    vector<char> out;
    bool flag = true;
    int ind = -1;
    for(int i = 0; i < 26; i++) {
        cin >> arr[i];
        if(arr[i]%2 == 1){
            if(!flag){
                cout << "NO" << endl;
                return 0;
            }
            flag = false;
            ind = i;
        }

        for(int j = 0; j < arr[i]/2; j++){
            out.pb((char)(i+'a'));
        }
    }

    cout << "YES" << endl;
    for(auto c: out) cout << c;
    if(!flag) cout << (char)(ind+'a');
    for(auto it = out.rbegin(); it != out.rend(); it++) cout << *it;
    return 0;
}