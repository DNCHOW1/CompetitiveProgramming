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
    int n, t; cin >> n >> t;
    v32 arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    switch(t){
        case 1:
            cout << "7" << endl;
            break;
        case 2:
            if(arr[0] > arr[1]) cout << "Bigger" << endl;
            else if(arr[0] == arr[1]) cout << "Equal" << endl;
            else cout << "Smaller" << endl;
            break;
        case 3: {
            int temp[3] = {arr[0], arr[1], arr[2]};
            sort(temp, temp+3);
            cout << temp[1] << endl;
            break;
        }
        case 4: {
            ll sm = 0;
            for(int num: arr) sm += num;
            cout << sm << endl;
            break;
        }
        case 5: {
            ll sm = 0;
            for(int num: arr) if(num%2 == 0) sm += num;
            cout << sm << endl;
            break;
        }
        case 6:
            for(int num: arr){
                num %= 26;
                cout << (char)(num + 'a');
            }
            cout << endl;
            break;
        case 7: {
            bool seen[200001] = {};
            seen[0] = true;
            int start = 0;
            while(start != n-1){
                start = arr[start];
                if(start >= n){
                    cout << "Out" << endl;
                    break;
                } else if(seen[start]){
                    cout << "Cyclic" << endl;
                    break;
                }
                seen[start] = true;
            }
            if(start == n-1) cout << "Done" << endl;
            break;
        }
    }
    return 0;
}