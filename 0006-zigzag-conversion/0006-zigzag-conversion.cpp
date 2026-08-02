class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s;

        vector<string> row(numRows);
        int cur = 0;
        bool down = true;

        for (char c:sk) {
            row[cur] += c;

            if (cur == 0)
                down = true;
            else if (cur == numRows - 1)
                down = false;

            cur += down ? 1 : -1;
        }

        string ans;
        for (string &x : row)
            ans += x;

        return ans;
    }
};