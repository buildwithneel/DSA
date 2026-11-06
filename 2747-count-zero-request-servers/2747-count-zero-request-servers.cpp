class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int q = queries.size();
        vector<int> order(q);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return queries[a] < queries[b];
        });

        vector<int> cnt(n + 1, 0), ans(q);
        int active = 0;
        int add = 0, drop = 0, m = logs.size();

        for (int idx : order) {
            int hi = queries[idx], lo = hi - x;

            while (add < m && logs[add][1] <= hi) {
                if (cnt[logs[add][0]]++ == 0) active++;
                add++;
            }
            while (drop < m && logs[drop][1] < lo) {
                if (--cnt[logs[drop][0]] == 0) active--;
                drop++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};