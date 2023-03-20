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
    int r1, r2, c1, c2;
    cin >> r1 >> c1;
    cin >> r2 >> c2;

    if((r1 == r2) && (c1 == c2)){
        cout << 0 << endl;
    } else if((abs(r1 - r2) + abs(c1 - c2)) <= 3 || (r1 + c1 == r2 + c2) || (r1 - c1 == r2 - c2)){
        // The 3 conditions given
        cout << 1 << endl;
    } else if(abs(r1 - r2) + abs(c1 - c2) <= 6 || (abs(c1 - r1)%2) == abs(c2 - r2)%2 ||
              abs((r1 + c1) - (r2 + c2)) <= 3 || abs((r1 - c1) - (r2 - c2)) <= 3){
        // first conditional is checking solely move C
        // second is checking if parities align, aka using move A + B
        // third checks move A + C(think instead of thin diagonal, it's a thick diagonal)
        // fourth checks move B + C(Same thinking as above)
        cout << 2 << endl;
    } else{
        cout << 3 << endl;
    }
    return 0;
}