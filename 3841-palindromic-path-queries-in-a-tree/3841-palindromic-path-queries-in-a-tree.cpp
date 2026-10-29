class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> par(n, -1), depth(n, 0), base(n), order, sz(n, 1), heavy(n, -1);
        order.reserve(n);

        base[0] = 1 << (s[0] - 'a');
        vector<int> st = {0};
        while (!st.empty()) {
            int v = st.back();
            st.pop_back();
            order.push_back(v);
            for (int w : adj[v]) {
                if (w == par[v]) continue;
                par[w] = v;
                depth[w] = depth[v] + 1;
                base[w] = base[v] ^ (1 << (s[w] - 'a'));
                st.push_back(w);
            }
        }

        for (int i = n - 1; i > 0; i--) sz[par[order[i]]] += sz[order[i]];
        for (int i = 1; i < n; i++) {
            int v = order[i], p = par[v];
            if (heavy[p] == -1 || sz[v] > sz[heavy[p]]) heavy[p] = v;
        }

        vector<int> head(n), tin(n);
        int timer = 0;
        st = {0};
        head[0] = 0;
        while (!st.empty()) {
            int v = st.back();
            st.pop_back();
            tin[v] = timer++;
            for (int w : adj[v]) {
                if (w == par[v] || w == heavy[v]) continue;
                head[w] = w;
                st.push_back(w);
            }
            if (heavy[v] != -1) {
                head[heavy[v]] = head[v];
                st.push_back(heavy[v]);
            }
        }

        vector<int> bit(n + 2, 0);
        auto add = [&](int i, int x) {
            for (i++; i <= n + 1; i += i & -i) bit[i] ^= x;
        };
        auto get = [&](int i) {
            int r = 0;
            for (i++; i > 0; i -= i & -i) r ^= bit[i];
            return r;
        };
        auto prefix = [&](int v) { return base[v] ^ get(tin[v]); };

        auto lca = [&](int a, int b) {
            while (head[a] != head[b]) {
                if (depth[head[a]] > depth[head[b]]) a = par[head[a]];
                else b = par[head[b]];
            }
            return depth[a] < depth[b] ? a : b;
        };

        vector<bool> ans;
        for (auto& q : queries) {
            int i = 0;
            while (q[i] != ' ') i++;
            i++;

            int u = 0;
            while (i < (int)q.size() && q[i] != ' ') u = u * 10 + (q[i++] - '0');

            if (q[0] == 'u') {
                char c = q.back();
                int d = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));
                s[u] = c;
                if (d) {
                    add(tin[u], d);
                    add(tin[u] + sz[u], d);
                }
            } else {
                i++;
                int v = 0;
                while (i < (int)q.size()) v = v * 10 + (q[i++] - '0');

                int l = lca(u, v);
                int mask = prefix(u) ^ prefix(v) ^ (1 << (s[l] - 'a'));
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};