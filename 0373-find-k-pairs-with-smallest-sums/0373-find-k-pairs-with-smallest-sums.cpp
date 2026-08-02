class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        vector<vector<int>> ans;

        auto cmp = [](auto &x, auto &y) {
            return x[0] > y[0];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < min((int)a.size(), k); i++)
            pq.push({a[i] + b[0], i, 0});

        while (k-- && !pq.empty()) {
            auto t = pq.top();
            pq.pop();

            int i = t[1], j = t[2];
            ans.push_back({a[i], b[j]});

            if (j + 1 < b.size())
                pq.push({a[i] + b[j + 1], i, j + 1});
        }

        return ans;
    }
};