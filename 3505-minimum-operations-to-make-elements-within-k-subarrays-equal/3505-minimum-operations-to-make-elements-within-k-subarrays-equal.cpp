class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        const long long INF = LLONG_MAX / 4;

        multiset<int> lo, hi;
        long long sLo = 0, sHi = 0;

        auto balance = [&]() {
            int target = (lo.size() + hi.size() + 1) / 2;
            while ((int)lo.size() > target) {
                auto it = prev(lo.end());
                sLo -= *it;
                sHi += *it;
                hi.insert(*it);
                lo.erase(it);
            }
            while ((int)lo.size() < target) {
                auto it = hi.begin();
                sHi -= *it;
                sLo += *it;
                lo.insert(*it);
                hi.erase(it);
            }
        };

        auto add = [&](int v) {
            if (lo.empty() || v <= *lo.rbegin()) {
                lo.insert(v);
                sLo += v;
            } else {
                hi.insert(v);
                sHi += v;
            }
            balance();
        };

        auto remove = [&](int v) {
            if (v <= *lo.rbegin()) {
                lo.erase(lo.find(v));
                sLo -= v;
            } else {
                hi.erase(hi.find(v));
                sHi -= v;
            }
            balance();
        };

        int windows = n - x + 1;
        vector<long long> cost(windows);

        for (int i = 0; i < n; i++) {
            add(nums[i]);
            if (i >= x) remove(nums[i - x]);
            if (i >= x - 1) {
                long long med = *lo.rbegin();
                cost[i - x + 1] = med * (long long)lo.size() - sLo + sHi - med * (long long)hi.size();
            }
        }

        vector<long long> prevRow(n + 1, 0), cur(n + 1);
        for (int j = 1; j <= k; j++) {
            cur[0] = INF;
            for (int i = 1; i <= n; i++) {
                cur[i] = cur[i - 1];
                if (i >= x && prevRow[i - x] < INF) {
                    cur[i] = min(cur[i], prevRow[i - x] + cost[i - x]);
                }
            }
            swap(prevRow, cur);
        }

        return prevRow[n];
    }
};