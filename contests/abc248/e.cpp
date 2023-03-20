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

// Mistake with conceptualizing # of lines possible, AT MOST N*(N-1)/2
// Mistake with using point slope form, slope could lead to floating point precision errors
// Mistake with representing used lined
    // With a 2d bool array, you can think of i and j as line passing through i,j
    // IMPORTANT: Once done with i, never use again. But j used, SO YOU HAVE TO ITERATE IN N^2

ll X[301], Y[301];
vector<vector<bool>> flag(301, vector<bool>(301, true));

bool colinear(){ // manipulate point slope form so you don't have to deal with float point vals

}

int main(){
    int n, K; cin >> n >> K;
    for(int i = 0; i < n; i++) cin >> X[i] >> Y[i];

    if(K == 1) cout << "Infinity" << endl;
    else{
        for(int i = 0; i < n-1; i++){
            for(int j = i + 1; j < n; j++){
                v32 temp;
                for(int k = j + 1; k < n; k++){

                }
            }
        }
    }
    return 0;
}