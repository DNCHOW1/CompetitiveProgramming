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

bool check(int x, const v32& a){ // x is the amount of seconds you get extra
    int uses = 0;
    for(int i = 0; i < a.size(); i++){
        int temp = a[i] - x;
        if(temp > 0) uses += temp;
    }
    return uses <= x;
}

void solve(){
    int n; cin >> n;
    v32 a(n+1);
    a[0]++;
    for(int i = 0; i < n-1; i++){
        int temp; cin >> temp;
        a[temp]++;
    }
    sort(a.rbegin(), a.rend()); // sort it by decreasing order I think, from top level people
    while(!a.empty() && a.back() == 0) a.pop_back();

    int sz = a.size();
    ll ans = sz;
    for(int i = 0; i < a.size(); i++) a[i] = max(0, a[i] + i - sz);
    sort(a.rbegin(), a.rend());
    while(!a.empty() && a.back() == 0) a.pop_back();

    ll extra = 0;
    ll l = 0, r = 2e5;
    while(l <= r){
        ll mid = (r - l)/2 + l;
        if(check(mid, a)) { extra = mid; r = mid - 1; }
        else l = mid + 1;
    }

    // while(!a.empty()){
    //     for(int i = 0; i < a.size(); i++){
    //         if(i == 0) a[i] = max(0, a[i]-2);
    //         else a[i]--;
    //     }
    //     sort(a.rbegin(), a.rend());
    //     while(!a.empty() && a.back() == 0) a.pop_back();
    //     ans++;
    // }
    cout << ans+extra << endl;
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        solve();
    }
    return 0;
}