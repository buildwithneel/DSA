class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        for (int l = 1; l <= n / 2; l++) {
            if (n % l) continue;

            bool ok = true;
            for (int i = l; i < n; i++) {
                if (s[i] != s[i % l]) {
                    ok = false;
                    break;
                }
            }

            if (ok) return true;
        }

        return false;
    }
};