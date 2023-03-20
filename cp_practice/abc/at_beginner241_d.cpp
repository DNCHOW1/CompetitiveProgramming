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
    int q; cin >> q;
    map<ll, ll> a; a[-INF] = INF; // pad on the left
    for(int i = 0; i < q; i++){
        ll n, x, k; cin >> n >> x;
        if(n == 1) a[x]++;
        else{
            cin >> k;
            if(n == 2){
                auto it = a.lower_bound(x);
                if(a.count(x) == 0) it--;
                while(it != a.end() && it->f != -INF && k > it->s) { 
                    k -= it->s;
                    it--;
                }
                cout << ((it == a.end() || it->f == -INF) ? -1: it->f) << endl;
            } else{
                auto it = a.lower_bound(x);
                while(it != a.end() && k > it->s) { 
                    k -= it->s;
                    it++;
                }
                cout << ((it == a.end()) ? -1: it->f) << endl;
            }
        }
    }
    return 0;
}