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

double dist(double x, double y, double ex, double ey){
    return sqrt(pow(ex-x,2)+pow(ey-y,2));
}

int main(){
    double x, y; cin >> x >> y;
    double ex, ey; cin >> ex >> ey;
    ll n; cin >> n;
    vector<double> mins(n+1, 1e18);
    vector<pair<double, double>> arr(n);
    priority_queue<pair<double, ll>, vector<pair<double, ll>>, greater<pair<double, ll>>> q; // seconds, curr_index
    for(ll i = 0; i < n; i++){
        double a, b; cin >> a >> b;
        arr[i] = {a, b};
        q.push({dist(x, y, a, b)/5.0, i});
    }

    arr.pb({ex, ey});
    q.push({dist(x, y, ex, ey)/5.0, n}); // we want a possibility where we run straight to the end
    while(!q.empty()){
        auto tp = q.top(); q.pop();
        double distance = tp.f;
        ll currI = tp.s;
        if(currI == n) {
            cout << fixed << setprecision(6) << distance << endl;
            break;
        }
        if(distance >= mins[currI]) continue;
        mins[currI] = distance;

        for(ll i = 0; i <= n; i++){
            if(i != currI){
                double calc = dist(arr[currI].f, arr[currI].s, arr[i].f, arr[i].s);
                double mn = min(2 + abs(calc-50.0)/5.0, calc/5.0);
                q.push({distance+mn, i});
            }
        }   
    }
    return 0;
}