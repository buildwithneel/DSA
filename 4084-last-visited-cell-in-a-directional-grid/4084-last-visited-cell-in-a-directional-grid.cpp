class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        auto limatecega = grid;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int r = 0, c = 0;
        vis[r][c] = true;
        while(true) {
            int x = r, y = c;
            if(grid[r][c] == 'L') c--;
            else if(grid[r][c] == 'R') c++;
            else if(grid[r][c] == 'U') r--;
            else if(grid[r][c] == 'D') r++;
            if(r < 0 || r >= m || c < 0 || c >= n || vis[r][c]) {
                return {x, y};
            }
            vis[r][c] = true;
        }
    }
};