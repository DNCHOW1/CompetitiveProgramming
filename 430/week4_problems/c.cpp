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

// Trying to do the DSU defined by USACO from memory
struct DSU {
    v64 arr; // we want this to store not the size of the disjoint set, but the summation of the people
    DSU(v64& coaches) { arr = coaches; }

    ll get(ll x) { return (arr[x] < 0) ? x : arr[x] = get(arr[x]); }

    ll size(ll x){ return -arr[get(x)]; }

    bool same_set(ll x, ll y){ return get(x) == get(y); }

    bool unite(ll x, ll y){ // return where unite was successful or not, also checks fast
        ll a = get(x), b = get(y);
        if(a == b) return false;
        else if(size(b) > size(a)) swap(a, b);

        arr[a] += arr[b]; // Because negative you add their sizes
        arr[b] = a; // Now b is part of a set
        return true;
    }
};

ll up10(ll num){
    ll rem = num%10;
    return num + (rem == 0 ? 0 : 10-rem);
}

int main(){
    // chaos = round(set_size) -> UP nearest multiple of 10
    // disjoint trains, chaos = summation*(# segments)
    // maximum chaos?

    ll n; cin >> n; // # of coaches
    v64 coaches(n);
    v64 order(n);
    for(ll i = 0; i < n; i++) {
        cin >> coaches[i];
        coaches[i] *= -1;
    }
    for(ll i = 0; i < n; i++) {
        cin >> order[i];
        --order[i];
    }

    // Initialize the dsu using coaches
    DSU dsu(coaches);
    ll segments = 0;
    vector<bool> seen(n);
    ll mx = 0, curr = 0;

    // work backwards from all disjoint sets. Pop sets into existance using order[i]
    for(ll i = n-1; i >=0; i--){
        ll ind = order[i];
        seen[ind] = 1;
        if(ind != 0 && seen[ind-1]){
            curr -= up10(dsu.size(ind-1));
            dsu.unite(ind-1, ind);
            segments--;
        }
        if(ind != n-1 && seen[ind+1]){
            curr -= up10(dsu.size(ind+1));
            dsu.unite(ind+1, ind);
            segments--;
        }
        segments++; // we do this regardless as we WILL be considering a new coach
        curr += up10(dsu.size(ind));
        mx = max(mx, segments*curr);
    }
    cout << mx << endl;
    return 0;
}