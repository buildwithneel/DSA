class Solution {
public:
    string toHex(int num) {
        if (num == 0)
            return "0";
        string ans = "";
        string hex = "0123456789abcdef";
        unsigned int n = num;
        while (n > 0) {
            int digit = n & 15;
            ans += hex[digit];
            n = n >> 4;
        }reverse(ans.begin(), ans.end());
        return ans;
    }
};