class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();

        long long allLcm = 1;
        int mx = 0;
        for (int x : nums) {
            allLcm = lcm(allLcm, (long long)x);
            mx = max(mx, x);
        }
        long long limit = allLcm * mx;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long prod = 1, l = 1, g = 0;
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                l = lcm(l, (long long)nums[j]);
                g = gcd(g, (long long)nums[j]);

                if (prod == l * g) ans = max(ans, j - i + 1);
                if (prod > limit) break;
            }
        }

        return ans;
    }
};