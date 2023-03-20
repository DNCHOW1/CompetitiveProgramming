#include "stdio.h"
#include <bits/stdc++.h>

#define w first
#define v second

using namespace std;

const unsigned int large = 10e5 + 1;
int dp[3001][3001]{}; // If defined in main it leads to segmentation fault
                      // HOWEVER, defined up here is fine???

int main(){
    string s, t;
    cin >> s >> t;
    // Attempt at solution in editorial

    // building 2d array of matches
    for(size_t i = 1; i <= s.size(); i++){
        for(size_t j = 1; j <= t.size(); j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // traversing from bottom right till top left to find all the matches
    size_t n = s.size(), m = t.size();
    string ret;
    while(n >= 1 && m >= 1){
        if(s[n-1] == t[m-1]){
            ret += s[n-1];
            n--; m--;
        } else if(dp[n-1][m] > dp[n][m-1]){
            n--;
        } else{
            m--;
        }
    }
    
    for(int i = ret.size()-1; i >= 0; i--){
        cout << ret[i];
    }
    cout << endl;

    // My original solution before, fails 1 test case from TLE. Prob from string concatenation.
    // 3000 by 3000 is too large, for a string that is
    /*
    string dp[3005]{};

    for(size_t i = 0; i < s.size(); i++){
        string temp, diag = "", prev = ""; // Where prev is to the left of curr, diag is top left of curr
        for(size_t j = 0; j < t.size(); j++){ // top expanding in length
            temp = dp[j];
            if(t[j] == s[i]){
                dp[j] = diag + t[j];
            }
            else if(prev.size() > dp[j].size()) dp[j] = prev;


            prev = dp[j];
            diag = temp;
        }
    }

    cout << dp[t.size() - 1] << endl;
    */
    return 0;
}