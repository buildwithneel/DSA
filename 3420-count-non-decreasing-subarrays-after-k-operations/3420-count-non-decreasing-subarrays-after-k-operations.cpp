class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0, cost = 0;
        deque<pair<int, int>> dq;
        int j = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            int num = nums[i], count = 1;

            while (!dq.empty() && dq.back().first < num) {
                auto [val, cnt] = dq.back();
                dq.pop_back();
                cost += (long long)(num - val) * cnt;
                count += cnt;
            }
            dq.push_back({num, count});

            while (cost > k) {
                auto [val, cnt] = dq.front();
                dq.pop_front();
                cost -= val - nums[j];
                j--;
                if (cnt > 1) dq.push_front({val, cnt - 1});
            }

            ans += j - i + 1;
        }

        return ans;
    }
};