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

// Reflection
// Queues are a good idea, would simplify iteration
// Jerry Kurtin -> Greedily calculate for left, and then for right
//      You can simply calculate the trips for them in a dedicated for loop
//      At the end, take max(2*left, 2*right + 1)

int main(){
    ll c; cin >> c;
    while(c--){
        ll l, m; cin >> l >> m;
        v64 left;
        v64 right;
        l *= 100;
        ll sumL = 0, sumR = 0;
        while(m--){
            ll cm;
            string dir;
            // l is meters, 
            cin >> cm >> dir;
            if(dir == "left"){
                left.pb(cm);
                sumL += cm;
            } else{
                right.pb(cm);
                sumR += cm;
            }
        }

        // raw simulation
        ll L = 0, R = 0, curr = 0;
        ll cnt = 0;
        while(L < left.size() && R < right.size()){
            ll temp = 0;
            if(curr == 0){
                while(L < left.size() && temp + left[L] <= l){
                    temp += left[L++];
                }
            } else{
                while(R < right.size() && temp + right[R] <= l){
                    temp += right[R++];
                }
            }
            cnt++;
            curr = !curr;
        }

        // handle either left remaining or right remaining
        if(L < left.size()){
            while(L < left.size()){
                if(curr == 1){
                    cnt += (curr == 1); // msut go back to left
                    curr = 0;
                }
                ll tempSum = 0;
                while(L < left.size() && tempSum + left[L] <= l){
                    tempSum += left[L++];
                }
                curr = !curr;
                cnt++;
            }
        } else if(R < right.size()){
            while(R < right.size()){
                if(curr == 0){
                    cnt++; // msut go back to right
                    curr = 1;
                }
                ll tempSum = 0;
                while(R < right.size() && tempSum + right[R] <= l){
                    tempSum += right[R++];
                }
                curr = !curr;
                cnt++;
            }
        }

        cout << cnt << endl;

    }
    return 0;
}