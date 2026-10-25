class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        function<void(int, int)> fill = [&](int r, int c) {
            if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 1) return;
            grid[r][c] = 1;
            fill(r + 1, c);
            fill(r - 1, c);
            fill(r, c + 1);
            fill(r, c - 1);
        };
        for (int r = 0; r < m; r++) {
            fill(r, 0);
            fill(r, n - 1);
        }
        for (int c = 0; c < n; c++) {fill(0, c);
            fill(m - 1, c);}
        int count = 0;
        for (int r = 1; r < m - 1; r++) {
            for (int c = 1; c < n - 1; c++) {if (grid[r][c] == 0) {
                    count++;
                   fill(r, c);}  }  }
        return count;
    }
};