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
    int n, k, x;
    cin >> n >> k >> x;
    v32 a;
    for(int i = 0; i < n; i++){
        int temp; cin>>temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end(), greater<int>());
    for(auto &num: a){
        int dC = num / x;
        num -= (min(k, dC)*x);
        k = max(k - dC, 0);
        if(k == 0) break;
    }

    sort(a.begin(), a.end(), greater<int>());
    ll total = 0;
    for(auto &num: a){
        if(k > 0){
            num -= x;
            k--;
        }
        total += max(num, 0);
    }
    cout << total << endl;
    return 0;
}