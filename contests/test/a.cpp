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
    for(int i = 0; i < n; i++){
        long long a, b; cin >> a >> b;
        if(a == 0 && b == 0) cout << 1 << endl;
        else if(a != 0 && b != 0) cout << (a + b*2 + 1) << endl;
        else if(a != 0 && b == 0) cout << a+1 << endl;
        else cout << 1 << endl;
    }
    return 0;
}