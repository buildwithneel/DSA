class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(n, vector<bool>(n, false)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[1][i][j] = s1[i] == s2[j];}}
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                for (int j = 0; j + len <= n; j++) {
                    for (int k = 1; k < len; k++) {
                        bool noSwap = dp[k][i][j] && dp[len - k][i + k][j + k];
                        bool swap = dp[k][i][j + len - k] && dp[len - k][i + k][j];
                        if (noSwap || swap) {
                            dp[len][i][j] = true;
                            break;}
            }
     }}
     }return dp[n][0][0];
    }
};