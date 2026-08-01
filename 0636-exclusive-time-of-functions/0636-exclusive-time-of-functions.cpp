class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> st;
        int prevTime = 0;

        for (string log : logs) {
            stringstream ss(log);
            string id, type, time;

            getline(ss, id, ':');
            getline(ss, type, ':');
            getline(ss, time, ':');

            int func = stoi(id);
            int currTime = stoi(time);

            if (type == "start") {
                if (!st.empty()) {
                    ans[st.top()] += currTime - prevTime;
                }
                st.push(func);
                prevTime = currTime;
            } else {
                ans[st.top()] += currTime - prevTime + 1;
                st.pop();
                prevTime = currTime + 1;
            }
        }

        return ans;
    }
};