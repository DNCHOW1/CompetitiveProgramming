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
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        int n; cin >> n; // sum of this over all the test cases is 1e5
        map<int, int> seen;
        int mx = 0;
        for(int j = 0; j < n; j++){ // nlogn
            int temp; cin >> temp;
            seen[temp]++;
            mx = max(mx, seen[temp]);
        }

        ll count = 0; // logn
        while(mx < n){
            count += (1 + mx);
            mx += mx;
        }
        if(mx > n) count -= (mx - n);
        cout << count << endl; 
    }
    return 0;
}