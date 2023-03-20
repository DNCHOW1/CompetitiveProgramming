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



int main(){
    string in; cin >> in;

    // reverse 0->i [0, i)
    // reverse i->j [i, j)
    // reverse j->n [j, n)

    // reverse 0->i (inclusive) [0, i]
    // reverse i+1->j (inclusive) [i+1, j]
    // reverse j+1->in.size()-1 (inclusive) [j+1, n-1]
    string mn(in.size(), 'z');
    for(int i = 0; i < in.size()-2; i++){
        for(int j = i+1; j < in.size()-1; j++){

            string a, b, c;
            a = in.substr(0, i+1);
            b = in.substr(i+1, j-i);
            c =  in.substr(j+1, in.size()-j-1);

            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());
            
            // for(int a = 0; a <= (i-1)/2; a++) swap(temp[a], temp[i-a]);
            // for(int b = 0; b <= (j-i-1)/2; b++) swap(temp[i+1+b], temp[j-b]);
            // for(int c = 0; c <= (in.size()-j-2)/2; c++) swap(temp[j+1+c], temp[in.size()-1-c]);
            // mn = min(mn, temp);

            mn = min(mn, a+b+c);
        }
    }
    cout << mn << endl;
    return 0;
}