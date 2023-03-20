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

map<ll, int> memo;
int n, x;

// For some reason using a map is faster than using an unordered_map
int main(){
    // ll n,sum; cin>>n>>sum;
    // vector<ll>v(n);
    // for(int i=0;i<n;++i) cin>>v[i];
    // ll m=0,cnt=0;
    // map<ll,ll>mp;
    // for(int i=0;i<n;++i)
    // {
    // 	m+=v[i];
    // 	if(m==sum)cnt++;
    // 	if(mp.count(m-sum))
    // 	{
    // 		cnt+=mp[m-sum];
	// 	}
	// 	mp[m]++;
	// }
	// cout<<cnt<<endl;

    cin >> n >> x;
    ll start = 0;
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        start += temp;
        if(start == x) cnt++;
        else{
            if(memo.find(start-x) != memo.end()) cnt += memo[start-x];
        }
        memo[start]++;
    }
    cout << cnt << endl;

    // for(auto it = memo.begin(); it != memo.end(); it++){
    //     printf("%lld %d\n", it->f, it->s);
    // }

    // ll cnt = 0, iter = 0;
    // for(int i = 0; i < n; i++){
    //     if(arr[i] > x) continue;
    //     else if(arr[i] == x) {
    //         cnt++; continue;
    //     }
    //     int j = n - 1;
    //     while(j >= i && (psum[j + 1] - psum[i]) > x) {
    //         j--; iter++;
    //     }
    //     cnt += (psum[j+1] - psum[i]) == x;
    // }
    // cout << cnt << endl;
    return 0;
}