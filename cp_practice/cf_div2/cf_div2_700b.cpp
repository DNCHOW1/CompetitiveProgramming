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

int cnt = 0;

/*
1
320995 806131 3
783399 76765 77638
140538 647490 973129

1
320995 806131 3
76765 783399 77638
647490 140538 973129
*/
const int MAXN = 100010;
 
int A, B, n;
int a[MAXN], b[MAXN];
 
void solve2()
{
	scanf("%d%d%d", &A, &B, &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &b[i]);
	int64_t damage = 0;
	for (int i = 1; i <= n; ++i)
		damage += int64_t(b[i] + A - 1) / A * a[i];
	for (int i = 1; i <= n; ++i)
		if (B - (damage - a[i]) > 0) // uses one line if to basically find any a[i] that allows double takedown
		{
			puts("YES");
			return;
		}
	puts("NO");
}

void solve(){
    // missed key observation that you should leave most damaging enemy for last
    // if you don't, you could get chunked extremely early
    int x, y, n; // x is attack, y is health
    cin >> x >> y >> n;
    vector<double> a(n), b(n);
    vector<pair<double, double>> v;
    for(auto &aa: a) cin >> aa;
    for(auto &bb: b) cin >> bb;
    for(int i = 0; i < n; i++){
        v.pb(mp(a[i], b[i]));
    }
    sort(v.begin(), v.end()); // Extremely needed

    bool flag = false;
    for(int i = 0; i < n; i++){
        int tM = ceil(v[i].second/x), tH = ceil(y/v[i].first);
        if(i == n-1){
            if(y > 0){
                flag = (tM <= tH);
            }
        } else{
            y -= tM*v[i].first;
        }
    }
    if(flag) cout << "YES" << endl; // hero never dies
    else cout << "NO" << endl;
}

int main(){
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        cnt++;
        solve();
    }
    return 0;
}