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

int mod = 32768;

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x == 0){ cout << 0 << " "; continue; }

        int mn = 1000;
        for(int j = 0; j <= 15; j++){
            int temp = (x + j)%mod, t = temp;
            int cnt = 0;
            while(t != 0 && t % 2 == 0) { t/=2; cnt++; }
            // dbg(temp); dbg(cnt);
            int counter = 0;
            for(int k = 0; temp != 0 && k < 15 - cnt; k++){
                if(mod - temp < 15-cnt-k) { 
                    counter += (mod - temp);
                    break; 
                }
                temp = (2*temp)%mod;
                counter++;
            }
            // dbg(cnt); dbg(j);
            mn = min(mn, counter+j);
        }

        cout << mn << " ";
    }
    return 0;
}