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
    int n; cin >> n;
    set<string> seen;
    string h = "Cats are great! :D";
    string s = "Cats are not great :(";
    seen.insert("great");
    while(n--){
        // string fir, tmp, sec;
        // cin >> fir >> tmp >> sec;
        // if(seen.count(sec) == 1){
        //     seen.insert(fir);
        // }
        bool first = false;
        string in; cin >> in;
        char* tok = strtok(in, " ");
        string FIR, prev;
        while(tok){
            if(!first){
                first = true;
                FIR = tok;
            }
            prev = tok;
            tok = strtok(NULL, " ");
        }
        if(seen.count(prev) == 1){
            seen.insert(FIR);
        }
    }
    if(seen.count("cats") == 1){
        cout << h << endl;
    } else{
        cout << s << endl;
    }
    return 0;
}