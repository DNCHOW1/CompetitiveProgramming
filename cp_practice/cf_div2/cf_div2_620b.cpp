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

bool isPalin(string t){
    int sz = t.size();
    for(int i = 0; i < sz/2; i++){
        if(t[i] != t[sz-i-1]) return false;
    }
    return true;
}

string rev(string t){
    reverse(t.begin(), t.end());
    return t;
}

string solve(){
    int n, m; cin >> n >> m;
    vector<pair<string, string>> in;
    deque<string> out;
    int longest = 0;
    string lng;
    for(int i = 0; i < n; i++){
        string temp, tempR; cin >> temp;
        if(longest != m && isPalin(temp)){
            longest = m;
            lng = temp;
        } else{
            tempR = rev(temp);
            in.pb(mp(temp, tempR));
        }      
    }

    if(!in.empty()){
        for(int i = 0; i < in.size()-1; i++){
            dbg(i);
            for(int j = i+1; j < in.size(); j++){
                if(in[i].f == in[j].s){
                    // cout << i << " " << j << endl;
                    out.push_front(in[i].f);
                    out.push_back(in[j].f);
                }
            }
        }
    }
    int sz = out.size()/2;
    string output = "";
    while(!out.empty()){
        if(out.size() == sz) output+= lng;
        auto curr = out.front(); out.pop_front();
        output+= curr;
    }
    if(output == "" && longest != 0) return lng;
    return output;
}

int main(){
    // string temp; cin >> temp;
    // cout << isPalin(temp) << endl;


    string temp = solve();
    cout << temp.size() << endl;
    cout << temp << endl;
    return 0;
}