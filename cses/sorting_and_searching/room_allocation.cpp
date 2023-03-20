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
    int n, a, b;
    cin >> n;
    vector<pair<p32, int>> arr;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        arr.push_back(make_pair(make_pair(a, b), i));
    }
    
    sort(arr.begin(), arr.end()); // nlogn
    priority_queue<p32, vector<p32>, greater<p32>> min_heap; // pass in pair: (departure, rms)
    int curr = 1, rms = -5;
    v32 toPrint(n);
    for(auto& [times, ind]: arr){
        if(min_heap.empty()){ // Very rare
            curr = 1;
        } else if(times.f > min_heap.top().first){
            curr = min_heap.top().second; min_heap.pop();
        } else{
            curr = rms + 1;
        }
        rms = max(rms, curr);
        // toPrint.push_back(curr);
        toPrint[ind] = curr;
        min_heap.push(make_pair(times.s, curr));
    }
    cout << rms << endl;
    for(auto& num: toPrint) cout << num << " ";
    cout << endl;
    return 0;
}