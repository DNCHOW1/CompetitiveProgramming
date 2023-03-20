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
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define f first
#define s second
#define INF 2e18
ll MOD9 = 998244353;
ll MOD1 = 1e9 + 7;
 

int main(){
    int n; cin >> n;

    int offset = 0;
    v32 circle, temp;
    for(size_t i = 1; i <= n; i++) circle.push_back(i);

    // while(circle.size() > 1){
    //     for(size_t i = 0; i < circle.size(); i++){
    //         if(i % 2 == offset) temp.push_back(circle[i]);
    //         else cout << circle[i] << " ";
    //     }

    //     offset = circle.size()%2;
    //     circle.swap(temp);
    //     temp.clear();
    // }
    // if(!circle.empty()) cout << circle[0];
    // cout << endl;


    // set<int> circle;
    // for(int i = 1; i <= n; i++) circle.insert(circle.end(), i);

    // v32 temp;
    // auto it = ++circle.begin();
    // while(circle.size() > 1){
    //     cout << *it << " ";
    //     temp.push_back(*it);

    //     if(++it == circle.end()){
    //         for(auto& x: temp) circle.erase(x);
    //         temp = {};
    //         it = ++circle.begin();
    //     } else if(++it == circle.end()){
    //         for(auto& x: temp) circle.erase(x);
    //         temp = {};
    //         it = circle.begin();
    //     }
    // }

    // if(!circle.empty()) cout << *circle.begin() << endl;
    return 0;
}