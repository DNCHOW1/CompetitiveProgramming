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

void solve(int n) {
    // arr 1 & 2
    int p1 = 0, p2 = 0;
    for(int i = 0; i < n; i++){
        int num;
        string in; 
        cin >> in >> num;
        if(in == "DROP"){
            cout << "DROP 2 " << num << endl;
            p2 += num;
        } else{
            if(p1 == 0){
                cout << "MOVE 2->1 " << p2 << endl;
                p1 += p2;
                p2 = 0;
            }
            int mn = min(p1, num);
            cout << "TAKE 1 " << mn << endl;
            p1 -= mn;
            num -= mn;

            if(num != 0){
                cout << "MOVE 2->1 " << p2 << endl;
                p1 += p2;
                p2 = 0;
                mn = min(p1, num);
                cout << "TAKE 1 " << mn << endl;
                p1 -= mn;
                num -= mn;
            }
        }
    }

}

int main(){
    int n = -1;
    while(true){
        cin >> n;
        if(n == 0) break;
        solve(n);
        cout << endl;
    }
    return 0;
}