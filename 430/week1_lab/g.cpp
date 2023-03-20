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
#define nl '\n'
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

/*
* Review on iterating through the basic data structures
* Map is not a random access iterator but a bidirectional iterator
*/

int main(){
    string in; cin >> in;
    map<char, ll> mp;
    for(char c: in){
        mp[c]++;
    }

    ll mn = 1e18;
    ll sum = 0;
    for(auto it=mp.begin(); it != mp.end(); it++){
        mn = min(it->s, mn);
        sum += pow(it->s, 2);
    }
    cout << sum + (7*mn*(mp.size() == 3)) << endl; 
    return 0;
}