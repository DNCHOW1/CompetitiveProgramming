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

char a[200005]{};
bool seen[26]{};

void solve(){
    for(int i = 0; i < 26; i++) seen[i] = false;
    int n, m; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; i++) {
        char temp; cin >> temp;
        seen[temp-97] = true;
    }

    // Idea is to use the largest distance between occurences
    // initialize occurences with a 0
    v32 occur = {0};
    for(int i = 0; i < n; i++){
        if(seen[a[i] - 97]) occur.pb(i);
    }

    int dist = 0;
    for(int i = 1; i < occur.size(); i++) {
        dist = max(dist, occur[i] - occur[i-1]);
    }
    cout << dist << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
    return 0;
}