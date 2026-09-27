class Solution {
public:
    set<string> solve(string &s, int &i) {
        set<string> res;
        set<string> cur;
        cur.insert("");

        while (i < s.size() && s[i] != '}') {
            if (s[i] == '{') {
                i++;
                set<string> temp = solve(s, i);
                i++;

                set<string> next;

                for (string a : cur) {
                    for (string b : temp) {
                        next.insert(a + b);
                    }
                }

                cur = next;
            }
            else if (s[i] == ',') {
                for (string x : cur)
                    res.insert(x);

                cur.clear();
                cur.insert("");
                i++;
            }
            else {
                char c = s[i];

                set<string> next;

                for (string x : cur)
                    next.insert(x + c);

                cur = next;
                i++;
            }
        }

        for (string x : cur)
            res.insert(x);

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ans = solve(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};