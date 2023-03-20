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

int dp[1003]{};

int calc(int a, int b){
    int diff = 0;
    while(a != 0){
        if(a%10 != b%10){
            diff++;
        }
        a/=10;
        b/=10;
    }
    return diff;
}

int solve(){
    int n; cin >> n;
    if(n%7 == 0) return n;

    int dig = 0, t = n;
    while(t != 0){
        t /= 10;
        dig++;
    }
    p32 mn = {5, 100};
    if(dig == 2){
        for(int i = 10; i <= 99; i++){
            if(dp[i]){
                mn = min(mn, mp(calc(n, i), i));
            }
        }
    } else{ // dig == 3
        for(int i = 100; i <= 999; i++){
            if(dp[i]){
                mn = min(mn, mp(calc(n, i), i));
            }
        }
    }
    return mn.s;
}

int main(){
    int t; cin >> t;
    for(int i = 14; i <= 999; i+=7){
        dp[i] = 1;
    }

    for(int i = 0; i < t; i++) cout << solve() << endl;
    return 0;
}