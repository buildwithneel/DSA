class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<int, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            return x[1] < y[1];
        });

        vector<int> pre(n);

        for (int i = 0; i < n; i++) {
            int lo = 0, hi = i - 1;
            pre[i] = -1;

            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                if (a[mid][1] < a[i][0]) {
                    pre[i] = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }

        vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));
        vector<vector<vector<int>>> path(
            n + 1,
            vector<vector<int>>(5)
        );

        for (int i = 1; i <= n; i++) {

            for (int k = 1; k <= 4; k++) {
                dp[i][k] = dp[i - 1][k];
                path[i][k] = path[i - 1][k];

                int p = pre[i - 1] + 1;

                long long val = dp[p][k - 1] + a[i - 1][2];

                vector<int> cur = path[p][k - 1];
                cur.push_back(a[i - 1][3]);

                sort(cur.begin(), cur.end());

                if (val > dp[i][k] ||
                    (val == dp[i][k] && cur < path[i][k])) {

                    dp[i][k] = val;
                    path[i][k] = cur;
                }
            }
        }

        vector<int> ans;

        for (int k = 1; k <= 4; k++) {
            if (dp[n][k] > dp[n][ans.size()] ||
                (dp[n][k] == dp[n][ans.size()] &&
                 path[n][k] < ans)) {
                ans = path[n][k];
            }
        }

        return ans;
    }
};