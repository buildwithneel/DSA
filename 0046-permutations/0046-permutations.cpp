class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();

        function<void(int)> dfs = [&](int start) {
            if (start == n) {
                res.push_back(nums);
                return;
            }

            for (int i = start; i < n; i++) {
                swap(nums[start], nums[i]);
                dfs(start + 1);
                swap(nums[start], nums[i]);
            }
        };

        dfs(0);
        return res;
    }
};