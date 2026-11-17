class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                int best = INF;

                for (int d = 1; d < len; d++) {
                    if (len % d) continue;
                    int m = len / d, changes = 0;

                    for (int r = 0; r < d; r++) {
                        for (int q = 0; q < m / 2; q++) {
                            if (s[i + r + q * d] != s[i + r + (m - 1 - q) * d]) changes++;
                        }
                    }

                    best = min(best, changes);
                }

                cost[i][j] = best;
            }
        }

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;

        for (int p = 1; p <= k; p++) {
            for (int i = 2 * p; i <= n; i++) {
                for (int j = 2 * (p - 1); j <= i - 2; j++) {
                    if (dp[p - 1][j] < INF) {
                        dp[p][i] = min(dp[p][i], dp[p - 1][j] + cost[j][i - 1]);
                    }
                }
            }
        }

        return dp[k][n];
    }
};