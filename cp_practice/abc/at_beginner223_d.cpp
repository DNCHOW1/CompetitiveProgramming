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
    int n, m; cin >> n >> m;
    v64 par(n+1);
    vv32 adj(n+1, v32());
    int cnt = n;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        cnt -= (par[b] == 0);
        par[b]++;
    }

    {
    // 2->(3, 4), 6->(1, 5)
    // 2 3 4 6 1 5
    // print 2
    // subtract par count from 3 and 4, both respective counts 0
    // print 3
    // print 4
    // print 6, sub parent count from 1 and 5, both counts 0
    // print 1
    // print 5

    // 2->(8, 9), 6->(1, 5), 4->(3)
    // 2 4 3 6 1 5 7 8 9
    // print 2, sub 8 and 9(both pars 0)
    // print 4, sub 3(par 0 and less 4, print 3)
    // print 6, sub 1 and 5(both pars 0, print 1 then 5)
    // print 8
    // print 9

    // 2->(5, 1), 1->(5), 3->(1)
    // 2 3 1 4 5
    // print 2, sub 1 and 5 (p: 1 1)
    // print 3, sub 1(p:0 and 1 < 3, print 1 and sub 1 from children)
    // print 4
    // print 5

    // 2->(1, 3), 4->(1)
    // print 2
    // subtract parent count from 1, it still has parent count of 1 {IF IT HAD PARENT COUNT 0 AND LESS THAN CURR, PRINT}
    // subtract parent count from 3, it has parent count of 0
    // print 3
    // print 4, subtract count from 1 and print 1
    }

    // traverse initially to print out #'s that aren't used before
    // b has to hold set of the parents?

    // traverse initially to print out #'s with no parents
    // if(cnt == 0){
    //     cout << -1 << endl;
    //     return 0;
    // }
    priority_queue<int, vector<int>, greater<int>> heap;
    for(int i = 1; i <= n; i++){
        if(par[i] == 0){
            heap.push(i);
        }
    }
    v32 ans;
    while(!heap.empty()){
        int i = heap.top(); heap.pop();
        ans.pb(i);
        for(auto &x: adj[i]){
            par[x]--;
            if(par[x] == 0) heap.push(x);
        }
    }
    
    bool flag = true;
    for(auto &x: par){
        if(x != 0){
            flag = false;
            break;
        }
    }
    if(flag){
        for(auto &x: ans){
            cout << x << " ";
        }
        cout << endl;
    } else{
        cout << -1 << endl;
    }
    return 0;
}