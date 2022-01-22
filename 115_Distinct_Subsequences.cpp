#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        int sL = s.length();
        int tL = t.length();
        vector<vector<unsigned int>> dp(tL+1, vector<unsigned int>(sL+1, 0));
        for(int i = 0; i < sL; i++) dp[0][i] = 1;
        for(int i = 1; i <= tL; i++){
            for(int j = 1; j <= sL; j++){
                if(i > j) dp[i][j] = 0;
                else if(t[i-1] == s[j-1]){
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[tL][sL];
    }
};