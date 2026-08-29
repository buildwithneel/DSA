class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> a;

        for (int x : nums)
            a.push_back(to_string(x));

        sort(a.begin(), a.end(), [](string x, string y) {
            return x + y > y + x;
        });

        if (a[0] == "0")
            return "0";

        string ans = "";

        for (string x : a)
            ans += x;

        return ans;
    }
};