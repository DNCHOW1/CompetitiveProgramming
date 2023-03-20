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

int valid[10]{};

int main(){
    string in; cin >> in;
    int cnt = 0;
    for(int i = 0; i < in.size(); i++){
        if(in[i] == 'o'){
            cnt++;
        }
    }

    if(cnt > 4){
        cout << 0 << endl;
    } else{
        ll tot = 0;
        for(int i = 0; i <= 9999; i++){
            vector<bool> flag(10);
            int X = i;
            for(int j = 0; j < 4; j++){
                flag[X%10] = true;
                X /= 10;
            }

            bool flag2 = true;
            for(int j = 0; j < 10; j++){
                if(flag[j] == true && in[j] == 'x') flag2 = false;
                else if(flag[j] == false && in[j] == 'o') flag2 = false;
            }
            tot += flag2;
        }
        cout << tot << endl;
    }
    return 0;
}