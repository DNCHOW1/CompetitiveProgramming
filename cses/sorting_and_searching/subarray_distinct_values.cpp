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

ll summation(ll n){
    return (n)*(n+1)/2;
}

int main(){
    ll n, k; cin >> n >> k;
    // ll n,k; n = k = 20000;
    v64 arr(n);
    map<int, int> counter;
    for(auto& x: arr) {
        cin >> x;
        counter.insert({x, 0});
    }

    ll cnt = 0;
    int ci, cj, pi, pj; ci = cj = pi = pj = 0;
    int unq = 0;

    while(cj != n){
        while(cj != n && unq + (counter[arr[cj]] == 0) <= k){
            unq += (counter[arr[cj]] == 0);
            counter[arr[cj]]++;
            cj++;
        }

        
        cnt += summation(cj - ci) - summation(max(pj - ci, 0)); // Calculate curr subarrays - overlapped subarrays
        // printf("(%lld %lld), (%lld, %lld), %lld\n", ci, cj, pi, pj, cnt);
        pi = ci; pj = cj;

        if(cj != n){ // means that the next cj index will have unique element, so have to delete 1 unique element
            while(counter[arr[ci]] - 1 != 0){
                counter[arr[ci]]--;
                ci++;
            }
            counter[arr[ci]]--;
            ci++; unq--;
        }
    }

    // while(j != n-1 || i != n-1){
    //     if(j != n-1) {
    //         j++;
    //         unq += counter[arr[j]] == 0;
    //         counter[arr[j]]++;

    //         while(unq > k && i != n){
    //             counter[arr[i]]--;
    //             unq -= (counter[arr[i]] == 0);
    //             i++;
    //         }
    //     } else{
    //         counter[arr[i]]--;
    //         unq -= (counter[arr[i]] == 0);
    //         i++;
    //     }

        // cout << i << " " << j << endl;
    //     cnt += (i != j);
    // }
    cout << cnt << endl;
    return 0;
}