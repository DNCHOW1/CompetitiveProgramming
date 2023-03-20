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
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        int n; cin >> n;
        int mx = 0;
        bool dupe = false;
        for(int j = 0; j < n; j++){
            int temp; cin >> temp;
            if(temp >= mx){
                if(temp >= mx + 2){
                    dupe = false;
                }
            }
            if(temp == mx || temp == mx + 1){
                dupe = true;
            } 
            mx = max(mx, temp);
        }
        if(dupe){
            cout << "yes" << endl;
        } else{
            cout << "no" << endl;
        }

    }
    return 0;
}