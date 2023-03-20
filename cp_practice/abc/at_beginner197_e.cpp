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

const int mx = 2e5 + 5;

int l[mx], r[mx];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < mx; i++){
        l[i] = INT32_MAX; r[i] = INT32_MIN;
    }

    int maxc = 0;
    for(int i = 0; i < n; i++){
        int x, c;
        cin >> x >> c;
        l[c] = min(l[c], x);
        r[c] = max(r[c], x);
        maxc = max(maxc, c);
    }

    p64 prev = {0, 0}; // keep track of number of moves
    int prevC = 0; // keeps track of the previous l and r to look at
    l[0] = 0; r[0] = 0;
    for(int i = 1; i <= maxc; i++){
        if(l[i] != INT32_MAX){
            p64 next = {0, 0};
            next.f = (r[i] - l[i]) + min(prev.f + abs(r[i] - l[prevC]), prev.s + abs(r[i] - r[prevC]));
            next.s = (r[i] - l[i]) + min(prev.f + abs(l[i] - l[prevC]), prev.s + abs(l[i] - r[prevC]));
            swap(next, prev);
            prevC = i;
        }
    }

    // cout << prevC << endl;
    // cout << prev.f << " " << prev.s << endl;
    cout << min(prev.f + abs(l[prevC]), prev.s + abs(r[prevC])) << endl;
    return 0;
}