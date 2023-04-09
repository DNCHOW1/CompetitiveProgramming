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
typedef vector<vector<double> > vvd;
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

vector<vvd> dp = vector<vvd>(10005, vvd(11, vector<double>(11, 1e18)));

/*
    dp relation:
    dp[0][0][0] = 0 <- cost on 0th day with no coupons and 0 in storage
    dp[i][j][k] = min{
        dp[i-1][j_][a_] + c*((1-j_)/10)*(k + a_ - b)
                        ** where a_ can range from 0->a;
                        ** j is the coupon in increments of 10
                        ** We want to store k at the end of day BUT also feed b to cats, use a_ from previous if exist

                        **  IMPORTANT **
                        * At j_ = 0, only then do you consider using j_???
                        *   Deal with case when coupon given and used in same day
                        * At j_ != 0, choosing to "hold" coupon
                        *   j_ only calculated when coupons[day] encountered
                        *   can only use j_ == j from previous day
    }
*/

double cost(ll c, ll j_, ll a_, ll b, ll k){
    if(k+a_-b < 0) return 1e18;
    return c*((10-j_)/10.0)*(k+a_-b);
}

int main(){
    ll a, b, c; cin >> a >> b >> c; // max storage, min to feed cat per day, $ amt for 1 bag
    ll n, m; cin >> n >> m;         // # days, # coupons
    v64 coupons(1e4 + 5);
    for(ll i = 0; i < m; i++){
        ll per, day; cin >> per >> day;
        coupons[day] = per;
    }

    dp[0][0][0] = 0;
    for(ll i = 1; i <= n; i++){
        for(ll j = 0; j <= 10; j++){
            for(ll k = 0; k <= a; k++){

                ll cou = coupons[i]/10;
                dp[i][cou][k] = min(dp[i][cou][k], dp[i-1][0][k] + c*k);
                if(cou > 0) // using coupon for day immediately
                    dp[i][0][k] = min(dp[i][0][k], dp[i-1][][] + cost(c, cou, 0, b, k));
                for(ll a_ = 0; a_ <= a; a_++){


                    dp[i][0][k] = min(dp[i][0][k], dp[i-1][j][a_] + cost(c, j, a_, b, k));
                    // if(j > 0)
                    //     dp[i][j][k] = min(dp[i][j][k]);

                }

            }
        }
    }
    return 0;
}