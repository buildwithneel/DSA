class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1000000007;

        long long dp = 1;
        long long last[26] = {};

        for (char c : s) {
            int x = c - 'a';

            long long ndp = (2 * dp - last[x] + MOD) % MOD;

            last[x] = dp;
            dp = ndp;
        }

        return (dp - 1 + MOD) % MOD;
    }
};