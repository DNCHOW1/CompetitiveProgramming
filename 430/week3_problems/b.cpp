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
    // n is up to 1000
    // #'s always pos and < 100

    int n;
    while(cin >> n){
        if(cin.eof()) break;

        int a, b;
        queue<int> Q;
        stack<int> S;
        priority_queue<int> PQ; // ALWAYS TAKING LARGER ELEMS FIRST, by default c++ uses max priority queue
        bool isQ = true, isS = true, isPQ = true;
        int sz = 0;

        while(n--){
            cin >> a >> b;
            if(a == 1){
                Q.push(b);
                S.push(b);
                PQ.push(b);
                sz++;
            } else{
                if(sz == 0){
                    isQ = isS = isPQ = false;
                    continue;
                }
                int qTop = Q.front(), sTop = S.top(), pqTop = PQ.top();
                Q.pop(); S.pop(); PQ.pop();
                isQ &= b == qTop;
                isS &= b == sTop;
                isPQ &= b == pqTop;
                sz--;
            }
        }
        if((isQ + isS + isPQ) > 1) cout << "not sure" << endl;
        else if((isQ + isS + isPQ) == 0) cout << "impossible" << endl;
        else if(isQ) cout << "queue" << endl;
        else if(isS) cout << "stack" << endl;
        else if(isPQ) cout << "priority queue" << endl;
    }
    return 0;
}