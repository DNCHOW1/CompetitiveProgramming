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
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define f first
#define s second
#define INF 2e18
ll MOD9 = 998244353;
ll MOD1 = 1e9 + 7;

long long arr[21]{};

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int low = INT32_MAX;
    // key is doing bitwise exhaustive search: binary represents the BARS seperating subsets!!!
    for(int i = 0; i < (1 << (n-1)); i++){ // go through all the subsets for the bars
        int xor_res = 0;
        int temp = 0;
        for(int j = 0; j < (n-1); j++){
            temp |= arr[n-1-j];
            if((1 << j) & i) {
                xor_res ^= temp;
                temp = 0;
            }
        }
        xor_res ^= (temp |= arr[0]);
        low = min(low, xor_res);
    }

    cout << low << endl;
    return 0;
}