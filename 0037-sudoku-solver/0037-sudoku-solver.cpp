class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int rows[9] = {}, cols[9] = {}, boxes[9] = {};
        vector<pair<int, int>> empty;

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    empty.push_back({r, c});
                } else {
                    int bit = 1 << (board[r][c] - '1');
                    rows[r] |= bit;
                    cols[c] |= bit;
                    boxes[(r / 3) * 3 + c / 3] |= bit;
                }
            }
        }

        function<bool(int)> solve = [&](int idx) {
            if (idx == (int)empty.size()) return true;

            int best = idx, bestCount = 10;
            for (int i = idx; i < (int)empty.size(); i++) {
                auto [r, c] = empty[i];
                int used = rows[r] | cols[c] | boxes[(r / 3) * 3 + c / 3];
                int count = 9 - __builtin_popcount(used);
                if (count < bestCount) {
                    bestCount = count;
                    best = i;
                    if (count <= 1) break;
                }
            }
            if (bestCount == 0) return false;

            swap(empty[idx], empty[best]);
            auto [r, c] = empty[idx];
            int b = (r / 3) * 3 + c / 3;
            int avail = ~(rows[r] | cols[c] | boxes[b]) & 0x1FF;

            while (avail) {
                int bit = avail & -avail;
                avail ^= bit;

                rows[r] |= bit;
                cols[c] |= bit;
                boxes[b] |= bit;
                board[r][c] = '1' + __builtin_ctz(bit);

                if (solve(idx + 1)) return true;

                rows[r] ^= bit;
                cols[c] ^= bit;
                boxes[b] ^= bit;
                board[r][c] = '.';
            }

            swap(empty[idx], empty[best]);
            return false;
        };

        solve(0);
    }
};