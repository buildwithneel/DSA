class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) children[parent[i]].push_back(i);

        vector<int> np = parent, saved(n, -1), order;
        order.reserve(n);
        int last[26];
        fill(last, last + 26, -1);

        vector<pair<int, bool>> st = {{0, false}};
        while (!st.empty()) {
            auto [v, exiting] = st.back();
            st.pop_back();
            int c = s[v] - 'a';

            if (exiting) {
                last[c] = saved[v];
                continue;
            }

            if (last[c] != -1) np[v] = last[c];
            saved[v] = last[c];
            last[c] = v;
            order.push_back(v);

            st.push_back({v, true});
            for (int w : children[v]) st.push_back({w, false});
        }

        vector<int> size(n, 1);
        for (int i = n - 1; i > 0; i--) {
            int v = order[i];
            size[np[v]] += size[v];
        }

        return size;
    }
};