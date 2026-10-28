class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if (n > m) {
            vector<vector<int>> t(n, vector<int>(m));
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++) t[j][i] = grid[i][j];
            grid = std::move(t);
            swap(m, n);
        }

        int mx = 0;
        for (auto& row : grid)
            for (int v : row) mx = max(mx, v);

        int B = 1;
        while (B <= mx) B <<= 1;

        vector<vector<char>> dp(n, vector<char>(B, 0));
        vector<char> next(B);

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                int v = grid[r][c];
                fill(next.begin(), next.end(), 0);

                if (r == 0 && c == 0) {
                    next[v] = 1;
                } else {
                    for (int x = 0; x < B; x++) {
                        if ((r > 0 && dp[c][x]) || (c > 0 && dp[c - 1][x])) {
                            next[x ^ v] = 1;
                        }
                    }
                }

                dp[c].swap(next);
            }
        }

        for (int x = 0; x < B; x++) {
            if (dp[n - 1][x]) return x;
        }

        return -1;
    }
};