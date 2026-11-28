class Solution {
public:
    long long maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> cnt(n + 1, 0), mult(n + 1, 0);
        for (auto& it : items) cnt[it[0]]++;
        for (int f = 1; f <= n; f++) {
            for (int m = f; m <= n; m += f) mult[f] += cnt[m];
        }

        long long mn = LLONG_MAX;
        for (auto& it : items) mn = min(mn, (long long)it[1]);

        vector<pair<long long, long long>> units;
        for (auto& it : items) {
            long long g = mult[it[0]] - 1;
            long long p = it[1];
            if (g > 0 && p < 2 * mn) units.push_back({p, g});
        }
        sort(units.begin(), units.end());

        long long rem = budget, a = 0;
        for (auto& [p, g] : units) {
            long long t = min(g, rem / p);
            a += t;
            rem -= t * p;
            if (t < g) break;
        }

        return 2 * a + rem / mn;
    }
};
