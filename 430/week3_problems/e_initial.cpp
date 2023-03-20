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

struct TreeNode {
    TreeNode* par;
    int val;
    int depth;

    TreeNode(TreeNode* par, int var, int depth) : par(par), val(val), depth(depth) {}
};

int main(){
    int n; cin >> n;
    vector<TreeNode*> tree(n + 1);
    tree[0] = new TreeNode(nullptr, 0, 0);
    for(int i = 1; i <= n; i++){
        char op;
        int v, w;
        cin >> op >> v;
        if(op == 'a'){
            tree[i] = new TreeNode(tree[v], i, tree[v]->depth + 1);

            // use dp here to get paths?
            for(ll j = 0; __; j++){
                dp[i][j] = dp[dp[i][]][];
            }

        } else if(op == 'b'){ // deal w/ the edge case where at elem "stack" is empty
            tree[i] = tree[v]->par;
            cout << tree[v]->val << endl; // no need to check if stack at this index is empty or not
        } else{
            cin >> w;
        }

    }
    return 0;
}