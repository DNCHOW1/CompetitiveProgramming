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
    list<char> norm;
    list<char> rev;
    string input; cin >> input;
    for(auto &x: input) { norm.push_back(x); rev.push_front(x); } 
    // char s; cin >> s;
    
    bool p = 0;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int n1;
        cin >> n1;
        if(n1 == 1) p = !p;
        else{
            int n2; cin >> n2;
            char t; cin >> t;
            if(n2 == 1){
                if(!p) {
                    norm.push_front(t);
                    rev.push_back(t);
                } else{
                    norm.push_back(t);
                    rev.push_front(t);
                }
            } else{
                if(!p) {
                    norm.push_back(t);
                    rev.push_front(t);
                } else{
                    norm.push_front(t);
                    rev.push_back(t);
                }
            }
        }
    }
    if(!p) for(auto it = norm.begin(); it != norm.end(); it++) cout << *it;
    else for(auto it = rev.begin(); it != rev.end(); it++) cout << *it;
    cout << endl;
    return 0;
}