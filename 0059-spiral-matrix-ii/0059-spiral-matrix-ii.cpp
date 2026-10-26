class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int num = 1;
        while (top <= bottom && left <= right) {
            for (int c = left; c <= right; c++) res[top][c] = num++;
            top++;
            for (int r = top; r <= bottom; r++) res[r][right] = num++;
            right--;
            for (int c = right; c >= left; c--) res[bottom][c] = num++;
            bottom--;
            for (int r = bottom; r >= top; r--) res[r][left] = num++;
            left++;
        }
        return res;
    }
};