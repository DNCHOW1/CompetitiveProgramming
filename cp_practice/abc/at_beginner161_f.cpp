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
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define dbg(x) cerr<<#x<<" = "<<x<<endl

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& pair) {
    return out << '(' << pair.first << ", " << pair.second << ')';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
    if(vec.empty()) return out << "[]";
    out << '[';
    for(size_t i = 0; i < vec.size()-1; i++) out << vec.at(i) << ", ";
    return out << vec.back() << ']';
}
ll INF = 2e18;
ll MOD9 = 998244353;
ll MOD1 = 1e9 + 7;

int main(){
    ll n; cin >> n;
    // for(ll n = 2; n <= 2055; n++){
    unordered_set<ll> choices = {2}; // could use an array size 1e6 instead

    ll m = n - 1;
    // O(sqrt(n))
    for(ll i = 2; i <= sqrt(m) + 1; i++){
        if(m % i == 0){
            choices.insert(i); 
            choices.insert(m / i);
        }
    }

    // O(sqrt(n)logn); could've combined the first loop with the 2nd one
    for(ll i = 2; i <= sqrt(n) + 1; i++){
        if(n % i == 0){
            ll temp = n;
            while(temp % i == 0) temp /= i;
            if(temp == 1 || (temp-1)%i == 0) choices.insert(i); // instead, this can be simplified to   
                                                            // temp % i == 1!!

            // ll tN = n;
            // while(tN % i == 0) tN /= i;
            // ll j = n / i;
            // if(tN)
            // if((j-1) % i == 0) choices.insert(i);
            // else{
            //     ll temp = n;
            //     while(temp % i == 0) temp /= i;
            //     if(temp == 1) choices.insert(i);
            // }
        }
    }
    choices.erase(1);
    ll total1 = choices.size();
    if(n - 1 > 2) total1 += 1;
    if(n > 2) total1 += 1;

    cout << total1 << endl;


    // Brute force solution
    // ll total2 = 0;
    // for(int i = 2; i <= n; i++){
    //     ll temp = n;
    //     while(i <= temp){
    //         if(temp % i == 0) temp /= i;
    //         else temp -= i;
    //     }
    //     if(temp == 1){
    //         total2++;
    //         // dbg(i);
    //     }
    // }
    // dbg(total2);
    return 0;
}