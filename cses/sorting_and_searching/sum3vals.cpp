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
    ll n, x; cin >> n >> x;
    if(n <= 2){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vp64 a(n);
    for(int i = 0; i < n; i++) {
        ll temp; cin >> temp;
        a[i] = {temp, i+1};
    }
    sort(a.begin(), a.end());
    
    for(int i = 0; i < n-2; i++){
        ll target = x - a[i].f;
        if(target <= 0) continue;
        // two pointers
        int l = i + 1, r = n-1;
        while(l < r){
            if(a[l].f + a[r].f > target) r--;
            else if(a[l].f + a[r].f < target) l++;
            else{
                printf("%lld %lld %lld\n", a[i].s, a[l].s, a[r].s);
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    // for(auto &b: a) cin >> b;
    // for(int i = 0; i < n-1; i++){
    //     map<ll, ll> seen;
    //     ll target = x - a[i];
    //     if(target <= 0) continue;
    //     for(int j = i+1; j < n; j++){
    //         if(seen.count(target - a[j])){
    //             printf("%d %d %d\n", i+1, j+1, seen[target-a[j]]+1);
    //             return 0;
    //         }
    //         seen.insert({a[j], j});
    //     }
    // }
    // cout << "IMPOSSIBLE" << endl;
    return 0;
}