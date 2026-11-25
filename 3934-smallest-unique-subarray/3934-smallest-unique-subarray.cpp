class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sa(n), rnk(nums.begin(), nums.end()), tmp(n);
        iota(sa.begin(), sa.end(), 0);

        for (int k = 1;; k <<= 1) {
            auto cmp = [&](int a, int b) {
                if (rnk[a] != rnk[b]) return rnk[a] < rnk[b];
                int ra = a + k < n ? rnk[a + k] : -1;
                int rb = b + k < n ? rnk[b + k] : -1;
                return ra < rb;
            };

            sort(sa.begin(), sa.end(), cmp);

            tmp[sa[0]] = 0;
            for (int i = 1; i < n; i++) {
                tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
            }
            rnk = tmp;

            if (rnk[sa[n - 1]] == n - 1) break;
        }

        vector<int> lcp(n + 1, 0);
        for (int i = 0, h = 0; i < n; i++) {
            if (rnk[i] > 0) {
                int j = sa[rnk[i] - 1];
                while (i + h < n && j + h < n && nums[i + h] == nums[j + h]) h++;
                lcp[rnk[i]] = h;
                if (h > 0) h--;
            } else {
                h = 0;
            }
        }

        int ans = n;
        for (int r = 0; r < n; r++) {
            int m = max(lcp[r], r + 1 < n ? lcp[r + 1] : 0);
            int len = m + 1;
            if (len <= n - sa[r]) ans = min(ans, len);
        }

        return ans;
    }
};