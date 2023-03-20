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
    int n, m; cin >> n >> m;
    v32 pos(n+2);
    v32 arr(1, 0);
    int count = 0;
    for(int i = 1; i <= n; i++){
        int temp; cin >> temp;
        pos[temp] = i; // Number associated with position
        arr.push_back(temp);
        count += (pos[temp-1] == 0);
    }
    pos[n+1] = INT32_MAX;
    // cout << count << endl; // initial count of the loops needed

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        int n1 = arr[a], n2 = arr[b];

        swap(arr[a], arr[b]);
        // n1 takes b pos and n2 takes a pos
        count -= ((b > pos[n1-1]) - (pos[n1] > pos[n1-1])) + ((b < pos[n1 + 1]) - (pos[n1] < pos[n1 + 1]));
        pos[n1] = b;
        count -= ((a > pos[n2-1]) - (pos[n2] > pos[n2-1])) + ((a < pos[n2+1]) - (pos[n2] < pos[n2+1]));
        pos[n2] = a;
        cout << count << endl;
    }
    return 0;
}