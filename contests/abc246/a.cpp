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
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if(a == c){
        if(b == f){
            cout << e << " " << d << endl;
        } else{
            cout << e << " " << b << endl;
        }
    } else if(a == e){
        if(b == d){
            cout << c << " " << f << endl;
        } else{
            cout << c << " " << b << endl;
        }
    } else{ // c == e
        if(b == d){
            cout << a << " " << f << endl;
        } else{
            cout << a << " " << d << endl;
        }
    }
    return 0;
}