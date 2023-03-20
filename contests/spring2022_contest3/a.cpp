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
#define ln '\n'
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define f first
#define s second
#define INF 2e18
ll MOD9 = 998244353;
ll MOD1 = 1e9 + 7;

// maybe dynamic programming instead??
// for # 724792, how to find?

// 10101010111010111011
// start left bound at nearest (2^ - 1)
 
bool calcA(int a, int b){ // a is upper, b is lower
    int ret = a;
    for(int i = a-1; ret > 0 && i >= b; i--){
        ret &= i;
    }
    return ret == 0;
}

int main(){
    int n; cin >> n;
    dbg(n);
    for(int i = 0; i < n; i++){

        // perform a binary search instead
        int k, j; cin >> k;
        j = 0;
        while((1 << (j + 1)) <= k) j++;
        cout << (1 << j) - 1 << endl;
        // int l = (1 << j)-1, r = k; // CHANGE THIS LEFT BOUND
        // while(l < r){
        //     int mid = (l + r)/2 + 1;
        //     if(calcA(k, mid)){
        //         l = mid;
        //     } else{
        //         r = mid - 1;
        //     }
        // }
        // cout << r << endl;


        // int res = k;
        // while((res &= (k - 1))) k--;
        // cout << k-1 << endl;
    }
    return 0;
}