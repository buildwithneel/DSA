class Solution {
public:
    int minCost(vector<vector<int>>& grid) {    
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<bool>>> reach(m, vector<vector<bool>>(n, vector<bool>(1024, false)));
        reach[0][0][grid[0][0]] = true;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                for (int x = 0; x < 1024; x++) {
                    if (!reach[r][c][x]) continue;
                    if (r + 1 < m) reach[r + 1][c][x ^ grid[r + 1][c]] = true;
                    if (c + 1 < n) reach[r][c + 1][x ^ grid[r][c + 1]] = true;
                }}}
        for (int x = 0; x < 1024; x++) {
            if (reach[m - 1][n - 1][x]) 
            return x;}
        return -1;
    }
};