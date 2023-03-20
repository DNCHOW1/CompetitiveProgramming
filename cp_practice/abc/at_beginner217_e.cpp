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
    int q; cin >> q;
    // v32 A;
    queue<int> A;
    // multiset<int> pq;
    priority_queue<int, v32, greater<int>> pq;
    // According to the editorial, using a priority queue + queue would probably be faster and more elegant
    // but why does changing pq from multiset to priority queue work?
    //  - BECAUSE ERASING AN ELEMENT REMOVES ALL INSTANCES OF THE ELEMENT!!!
    // using a priority queue took much less memory as well
    for(int i = 0; i < q; i++){
        int n; cin >> n;
        if(n == 1){
            int x; cin >> x;
            A.push(x);
        } else if(n == 2){
            if(pq.empty()) {
                auto fro = A.front(); A.pop();
                cout << fro << endl;
            }
            else{
                cout << pq.top() << endl;
                pq.pop();
            }
        } else{
            while(!A.empty()){
                auto fro = A.front(); A.pop();
                pq.push(fro);
            }
        }
    }
    return 0;
}