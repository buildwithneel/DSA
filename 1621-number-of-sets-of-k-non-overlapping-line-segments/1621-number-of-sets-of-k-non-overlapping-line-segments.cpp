class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1000000007;

        vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));

        for (int i = 0; i < n; i++)
            dp[i][0] = 1;

        for (int j = 1; j <= k; j++) {
            long long sum = 0;

            for (int i = 0; i < n; i++) {
                if (i > 0)
                    dp[i][j] = dp[i - 1][j];

                if (i >= 1) {
                    sum = (sum + dp[i - 1][j - 1]) % MOD;
                    dp[i][j] = (dp[i][j] + sum) % MOD;
                }
            }
        }
        return dp[n - 1][k];
    }
};