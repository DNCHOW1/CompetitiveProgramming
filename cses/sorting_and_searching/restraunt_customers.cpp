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
    vp32 customers;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        customers.push_back(make_pair(a, 1)); customers.push_back(make_pair(b, -1));
    }

    sort(customers.begin(), customers.end());
    long long curr = 0, maxC = INT32_MIN;
    for(int i = 0; i < customers.size(); i++){
        curr += customers[i].s;
        maxC = max(curr, maxC);
    }

    cout << maxC << endl;
    return 0;
}