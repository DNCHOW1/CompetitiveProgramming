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

bool checkString(string& S){
    return S != "union" && S != "intersection" && S != "difference";
}

// Reflection:
// Did not account for calculations being overrided, results also need to be within a stack
// Need to read problem more clearly to see inputs
// 

int main(){
    // groups can have up to 100 people
    // After groups there can be up to 100 instructions
    // In each instruction there can be up to 100 groups

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<string, set<string>> groups;
    string S;
    while(cin >> S){
        if(cin.eof()) break;
        if(S != "group" && checkString(S)){
            for(string str: groups[S]) cout << str << " ";
            cout << endl;
        } else if(S == "group"){
            string groupName;
            int n;
            cin >> groupName >> n;
            for(int i = 0; i < n; i++) {
                string t; cin >> t;
                groups[groupName].insert(t);
            }
        }
        else{
            // Keep a persistant set holding results WITHIN groups
            stack<string> stk;
            stack<set<string>*> res;
            stk.push(S);
            while(stk.size() != 1 || stk.top() != "-"){
                cin >> S;
                while(!stk.empty() && checkString(S) && checkString(stk.top())){ // Both are group names
                    string B = stk.top(); stk.pop(); // string before S, important for "difference"
                    string OP = stk.top(); stk.pop();

                    set<string>* one = nullptr;
                    set<string>* two = nullptr;
                    if(S == "-"){
                        two = res.top(); res.pop();
                    } else two = &groups[S];
                    if(B == "-"){
                        one = res.top(); res.pop();
                    } else one = &groups[B];
                    set<string>* temp = new set<string>;

                    if(OP == "union") {
                        for(auto it = one->begin(); it != one->end(); it++) temp->insert(*it);
                        for(auto it = two->begin(); it != two->end(); it++) temp->insert(*it);
                    } else if(OP == "intersection"){
                        for(auto it = one->begin(); it != one->end(); it++) {
                            if(two->count(*it) == 1) temp->insert(*it);
                        }
                    } else{ // difference
                        for(auto it = one->begin(); it != one->end(); it++) {
                            if(two->count(*it) == 0) temp->insert(*it);
                        }
                    }
                    S = "-";
                    res.push(temp);
                }
                stk.push(S);
            }
            auto tp = res.top();
            for(auto it = tp->begin(); it != tp->end(); it++) cout << *it << " ";
            cout << endl;
        }
    }
    return 0;
}