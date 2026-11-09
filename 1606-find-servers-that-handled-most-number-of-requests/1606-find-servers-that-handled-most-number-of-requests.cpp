class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> free;
        for (int i = 0; i < k; i++) free.insert(i);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;
        vector<int> handled(k, 0);

        for (int i = 0; i < arrival.size(); i++) {
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                free.insert(busy.top().second);
                busy.pop();
            }

            if (free.empty()) continue;

            auto it = free.lower_bound(i % k);
            if (it == free.end()) it = free.begin();

            int server = *it;
            free.erase(it);
            handled[server]++;
            busy.push({arrival[i] + load[i], server});
        }

        int best = *max_element(handled.begin(), handled.end());
        vector<int> res;
        for (int i = 0; i < k; i++) {
            if (handled[i] == best) res.push_back(i);
        }

        return res;
    }
};