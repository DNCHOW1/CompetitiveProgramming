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



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    deque<ll> left, right;
    int n; cin >> n;
    ll size = 0;
    while(n--){
        string op;
        ll m;
        cin >> op >> m;
        if(op == "get"){
            if(m < left.size()) cout << left[m] << endl;
            else cout << right[m-left.size()] << endl;
        } else{
            if(op == "push_back") right.push_back(m);
            else if(op == "push_front") left.push_front(m);
            else right.push_front(m); // because we always want to insert at (size+1)//2
            size++;

            // Need to rebalance so that the back of left is always the middle element
            // That way, when pushing mid we always push to right
            if(left.size() != (size+1)/2){
                if(left.size() > (size+1)/2){ // right too big, give to left
                    right.push_front(left.back());
                    left.pop_back();
                } else{ // left too big, give to right
                    left.push_back(right.front());
                    right.pop_front();
                }
            }
            // dbg(left.size());
            // dbg(right.size());
        }
    }
    return 0;
}