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
#define dbg(x) cerr<<#x<<" = "<<x<<nl

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    map<string, int> dict;
    v32 nums;
    for(int i = 0; i < n; i++){
        string name;
        int cats;
        cin >> name;
        cin >> cats;
        dict[name] = cats;
        nums.pb(cats);
    }

    sort(nums.begin(), nums.end());
    int q; cin >> q;
    while(q--){
        string s, t; cin >> s >> t;
        int ns = dict[s], nt = dict[t];
        int low, high;
        if(ns == nt){
            cout << s << " is tied with " << t << "!" << nl;
        } else{
            if (ns < nt){
            low = lower_bound(nums.begin(), nums.end(), nt) - upper_bound(nums.begin(), nums.end(), ns) + 1;
            high = upper_bound(nums.begin(), nums.end(), nt) - lower_bound(nums.begin(), nums.end(), ns) - 1;
            cout << s << " is " << low << "-" << high << " rank(s) below " << t << "!" << nl;
        } else{
            low = lower_bound(nums.begin(), nums.end(), ns) - upper_bound(nums.begin(), nums.end(), nt) + 1;
            high = upper_bound(nums.begin(), nums.end(), ns) - lower_bound(nums.begin(), nums.end(), nt) - 1;
            cout << s << " is " << low << "-" << high << " rank(s) above " << t << "!" << nl;

        }
        }
    }
    return 0;
}