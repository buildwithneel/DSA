class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;

                long long sum = 0;
                vector<pair<int, int>> stack = {{i, j}};
                sum += grid[i][j];
                grid[i][j] = 0;
                while (!stack.empty()) {
                    auto [r, c] = stack.back();                    stack.pop_back();
                    for (auto& d : dirs) {
                        int nr = r + d[0], nc = c + d[1];
                        if (nr < 0 || nc < 0 || nr >= m || nc >= n || grid[nr][nc] == 0) continue;
                        sum += grid[nr][nc];
                        grid[nr][nc] = 0;                       stack.push_back({nr, nc});
                    }
                }
                if (sum % k == 0) count++;
            }
        }
        return count;
    }
};