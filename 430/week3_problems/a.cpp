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

// Reflection:
// Didn't know that if map doesn't find an element, it auto emplaces map[elem] = 0 or whatever is default
// Read the problem and get the gist of it faster, no need to continually re-read

int main(){
    // Can be up to 2000 words
    // calc is up to 15 instructions    
    // we want a bidirectional mapping from var name -> num && num -> var name
    // NO TWO VARIABLES HAVE SAME NUMERIC VALUE AT THE SAME TIME
    // "defining again erases its old definition, OVERRIDE"
    map<string, ll> varToNum;
    map<ll, string> numToVar;
    string S, T, varName;
    ll num;
    while(cin >> S){
        if(cin.eof()) break;

        if(S == "def"){
            cin >> varName >> num;
            if(varToNum.count(varName) == 1) numToVar.erase(varToNum[varName]); // delete num mapping
            varToNum[varName] = num; // override varName if it exists
            numToVar[num] = varName; // Create bidirectional mapping
        } else if (S == "calc"){
            ll curr = 0;
            bool add = true, unknown = false;
            // unknown def can be used in the calc
            while(cin >> T){
                cout << T << " ";
                if(T == "=") break;
                if(unknown) continue;
                else if(T == "+" || T == "-") add = (T == "+");
                else{
                    if(varToNum.count(T) == 0){
                        unknown = true;
                        continue;
                    }
                    curr += ((add) ? varToNum[T] : -varToNum[T]);
                }
            }
            // dbg(varToNum.count("bar"));
            unknown |= (numToVar.count(curr) != 1);
            cout << ((unknown) ? "unknown" : numToVar[curr]) << endl;
            // dbg(curr);
        } else{ // clear, delete everything within two maps
            varToNum.clear();
            numToVar.clear();
        }
    }
    return 0;
}