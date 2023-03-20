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

int n; 
ll mx = 0;
int A[17][17];
bool used[17]{};
int cnt = 0;

void dfs(ll tot){
    if(cnt == 2*n){
        mx = max(mx, tot);
        return;
    }
    int i = 0;
    for(; i < 2*n-1; i++){
        if(!used[i]){
            used[i] = 1;
            break;
        }
    }
    for(int j = i + 1; j <= 2*n-1; j++){
        if(!used[j]){
            cnt += 2;
            used[j] = 1;
            dfs(tot^A[i][j]);
            used[j] = 0;
            cnt -= 2;
        }
    }
    used[i] = 0;
}

int main(){
    cin >> n;
    for(int i = 0; i < 2*n-1; i++){
        for(int j = i + 1; j <= 2*n-1; j++){
            cin >> A[i][j];
        }
    }

    dfs(0);
    cout << mx << endl;
    return 0;
}