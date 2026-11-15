class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long odd = 0, even = 1, res = 0;
        int parity = 0;

        for (int x : arr) {
            parity ^= x & 1;
            if (parity) {
                res += even;
                odd++;
            } else {
                res += odd;
                even++;
            }
        }

        return res % MOD;
    }
};