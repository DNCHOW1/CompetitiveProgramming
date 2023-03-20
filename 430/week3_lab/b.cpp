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
    ll n, m; cin >> n >> m; // # of researchers & number of minutes of inactivity
    priority_queue<p64, vp64, greater<p64>> futures;
    priority_queue<ll, v64, greater<ll>> open;
    for(ll i = 0; i < n; i++){
        ll a, S;
        cin >> a >> S;
        futures.push({a, S});
    }

    ll saved = 0;
    while(!futures.empty()){
        auto& [a, S] = futures.top();
        while(!open.empty() && a > open.top()+m) open.pop(); // what if more appear?
        if(!open.empty()){
            auto& tp = open.top();
            if(a >= tp && a <= tp+m){
                saved++;
                open.pop();
            }
        }
        open.push(a+S);
        futures.pop();
    }
    cout << saved << endl;
    return 0;
}