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
    int n, num; cin >> n;
    v32 orig(n), sorted(n);
    map<int ,int> dict;
    for(int i = 0; i < n; i++) {
        int m; cin>>m;
        orig[i] = m;
        sorted[i] = m;
        dict[m] = i;
    }
    cin >> num;

    int true_i;
    sort(sorted.begin(), sorted.end());
    for(int i = 0; i < n; i++){
        if(sorted[i] == num){
            true_i = i;
            break;
        }
    }

    int i = 0;
    while(i < n && orig[true_i] != num){
        while(orig[i] != sorted[i] && orig[true_i] != num){
            int curr_i = lower_bound(sorted.begin(), sorted.end(), orig[i]) - sorted.begin();
            swap(dict[orig[curr_i]], dict[orig[i]]); // swap the positions
            swap(orig[dict[orig[i]]], orig[dict[orig[curr_i]]]);
        }
        i++;
    }

    // cout << orig << endl;
    for(auto &x: orig) cout << x << " ";
    cout << endl;
    return 0;
}