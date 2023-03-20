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

bool ans[200005]{};

int main(){
    // Didn't get the insight to use the set's cardinality initially
    // MISSED WHAT PROBLEM WAS ASKING COMPLETELY
    // Trouble with conceptualizing case where card ==, spent time thinking and eventually figured to use 2 sets
        // With peek at editorial, realized that it could be simplified down to 1 set
    // When taking the iterator loc, did it on ca instead of a. That caused the wrong elements to be added
    int n, q; cin >> n;
    v32 a(n), b(n), ca, cb;
    set<int> seena, seenb, seenc;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        seena.insert(a[i]);
        ca.pb(seena.size());
    }
    int prev = 0;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        seenb.insert(b[i]);
        cb.pb(seenb.size());
        if(seenb.size() != prev){
            prev = seenb.size();
            int loc = lower_bound(ca.begin(), ca.end(), prev) - ca.begin();
            if(loc != n){
                if(seenc.count(a[loc]) == 0) seenc.insert(a[loc]);
                else seenc.erase(a[loc]);

                if(seenc.count(b[i]) == 0) seenc.insert(b[i]);
                else seenc.erase(b[i]);
            }
        }
        ans[i] = seenc.empty();
    }

    cin >> q;
    while(q--){
        int c, d; cin >> c >> d;
        c--, d--;
        if(ca[c] == cb[d] && ans[d]) // check if the cardinality is equal AND if they have equal elements when card is eq
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}