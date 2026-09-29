class Solution {
public:
    int dp[105][105][205];
    bool solve(vector<vector<char>>& grid, int i, int j, int bal) {
        int m = grid.size();
        int n = grid[0].size();
        if (i >= m || j >= n || bal < 0)
            return false;
        if (grid[i][j] == '(')
            bal++;
        else
            bal--;
        if (bal < 0)
            return false;
        if (i == m - 1 && j == n - 1)
            return bal == 0;
        if (dp[i][j][bal] != -1)
            return dp[i][j][bal];
        bool down = solve(grid, i + 1, j, bal);
        bool right = solve(grid, i, j + 1, bal);
        return dp[i][j][bal] = down || right;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if ((m + n - 1) % 2 != 0)
            return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;
        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, 0, 0);
    }
};