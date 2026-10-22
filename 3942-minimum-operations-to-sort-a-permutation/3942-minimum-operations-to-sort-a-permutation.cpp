class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        int z = find(nums.begin(), nums.end(), 0) - nums.begin();

        auto check = [&](int d) {
            for (int i = 1; i < n; i++) {
                int a = (z + (i - 1) * d % n + n) % n;
                int b = (z + i * d % n + n) % n;
                if (nums[a] > nums[b]) return false;
            }
            return true;
        };

        if (check(1))
            ans = min(ans, min(z, n - z + 2));

        if (check(-1))
            ans = min(ans, min(z + 2, n - z));

        return ans == INT_MAX ? -1 : ans;
    }
};