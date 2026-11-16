class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int m = num1.size(), n = num2.size();
        vector<int> res(m + n, 0);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int prod = (num1[i] - '0') * (num2[j] - '0') + res[i + j + 1];
                res[i + j + 1] = prod % 10;
                res[i + j] += prod / 10;
            }
        }

        string ans;
        int start = res[0] == 0 ? 1 : 0;
        for (int i = start; i < m + n; i++) ans += '0' + res[i];

        return ans;
    }
};