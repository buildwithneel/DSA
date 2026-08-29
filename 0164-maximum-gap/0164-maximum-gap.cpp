class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return 0;
        int mn = nums[0], mx = nums[0];
        for (int x : nums) {
            mn = min(mn, x);
            mx = max(mx, x);
        }
        if (mn == mx)
            return 0;
        int gap = (mx - mn + n - 2) / (n - 1);
        vector<int> bucketMin(n, INT_MAX);
        vector<int> bucketMax(n, INT_MIN);
        vector<bool> used(n, false);
        for (int x : nums) {
            int index = (x - mn) / gap;
            bucketMin[index] = min(bucketMin[index], x);
            bucketMax[index] = max(bucketMax[index], x);
            used[index] = true; }
        int ans = 0;
        int prev = mn;
        for (int i = 0; i < n; i++) {
            if (!used[i])
                continue;
            ans = max(ans, bucketMin[i] - prev);
            prev = bucketMax[i];}
        return ans;
    }
};