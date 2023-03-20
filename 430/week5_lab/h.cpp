#include <bits/stdc++.h>  
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

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

vp64 pairs;
set<string> out;
string in;
v64 subs;

void subset(ll i){
    if(i == pairs.size()){
        if(subs.size() == 0) return;
        set<ll> temp;
        for(auto ind: subs){
            temp.insert(pairs[ind].f);
            temp.insert(pairs[ind].s);
        }
        // add to out
        ll I = in.size() - 2*subs.size();
        string toAdd((int)I, '*');
        // toAdd.reserve(I);
        ll curr = 0;
        for(ll index = 0; index < in.size(); index++){
            if(temp.count(index) == 0){
                toAdd[curr++] = in[index];
            }
        }
        out.insert(toAdd);
        return;
    }
    for(ll index = i; index < pairs.size(); index++){
        subset(index+1);
        subs.pb(index);
        subset(index+1);
        subs.pop_back();
    }
}

int main(){
    // no more than 200 characters
    // 1 <= # pairs <= 10
    // 2^10 - 1 possible solutions max; iterate 200

    // whenever we encounter a ), we take the first () in the stack
    stack<ll> pos; // store 
    cin >> in;
    ll index = 0;

    for(auto c: in){
        if(c == '(') pos.push(index);
        else if(c == ')') {
            auto tp = pos.top(); pos.pop();
            pairs.pb({tp, index});
        }
        index++;
    }

    v64 subs;
    subset(0);

    for(auto& str: out) cout << str << endl;
    return 0;
}