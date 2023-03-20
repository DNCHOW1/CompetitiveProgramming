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

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    int n, k; cin >> n >> k;
    v64 a(n);
    ll mxSum = 0;
    // for(int i = 0; i < n; i++){
    //     cin >> a[i];
    //     mxSum = mxSum + a[i];
    // }
    for(auto &x: a) {
        cin >> x;
        mxSum += x;
    }

    auto comp = [&] (ll mx) {
        int groups = 0;
        ll temp = 0;
        for(auto &x: a){
            if(x > mx) return false;
            if((temp+=x) > mx){
                groups++;
                temp = x;
            }
        }
        return groups+(temp > 0) <= k;
    };

    ll l = 0, r = mxSum;
    while(l < r){
        ll mid = (l+r)/2; // Error was here, I had int instead of ll the whole time!!!
        if(comp(mid)){
            r = mid;
        } else{
            l = mid + 1;
        }
    }

	cout << l << '\n';
    return 0;
}