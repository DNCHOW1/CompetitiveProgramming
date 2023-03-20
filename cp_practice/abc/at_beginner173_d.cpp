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
    int n;
    cin >> n;
    v32 arr(n);
    for(auto &x: arr) cin >> x;
    sort(arr.begin(), arr.end(), greater<int>());

    queue<int> hold;

    long long total = 0;
    hold.push(arr[0]);
    for(int i = 1; i < n; i++){
        total += hold.front(); hold.pop();
        hold.push(arr[i]); hold.push(arr[i]);
    }

    cout << total << endl;
    return 0;
}