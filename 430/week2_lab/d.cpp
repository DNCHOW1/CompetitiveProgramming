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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

// 1 2 3 4 5 6 7
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string c;
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    while(cin >> c){
        if(cin.eof()) break;
        if(c == "#"){
            int n = right.top(); right.pop();
            cout << n << endl;
            if(right.size() < left.size()){
                int m = left.top(); left.pop();
                right.push(m);
            }
        } else {
            int num = stoi(c);
            right.push(num);
            if(right.size() > left.size() + 1){
                int k = right.top(); right.pop();
                left.push(k);
            } else if(left.size() > 0 && left.top() > right.top()){
                int l = left.top(); left.pop();
                int r = right.top(); right.pop();
                left.push(r);
                right.push(l);
            }
        }
    }
    return 0;
}