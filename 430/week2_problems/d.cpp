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

int timeToSec(string time){
    return ((int)time[0])*36000 + ((int)time[1])*3600 + ((int)time[3])*600 + ((int)time[4])*60 + ((int)time[6])*10 + (int)time[7];
}

int main(){
    string t1, t2;
    cin >> t1 >> t2;
    ll s1 = timeToSec(t1), s2 = timeToSec(t2), s3 = s2 - s1;
    
    if(s3 < 0) s3 += 3600*24;
    if(t1 != t2) printf("%02lld:%02lld:%02lld\n", s3/3600, (s3%3600)/60, ((s3%3600)%60));
    else cout << "24:00:00" << endl;
    return 0;
}