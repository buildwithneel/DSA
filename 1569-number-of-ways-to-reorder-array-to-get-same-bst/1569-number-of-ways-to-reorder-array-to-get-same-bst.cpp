class Solution {
public:
    const int mod = 1e9 + 7;

    long long comb[1001][1001];

    int solve(vector<int>& nums) {
        if(nums.size() <= 2) return 1;

        vector<int> left, right;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        long long l = solve(left);
        long long r = solve(right);

        return comb[nums.size() - 1][left.size()] * l % mod * r % mod;
    }

    int numOfWays(vector<int>& nums) {
        memset(comb, 0, sizeof(comb));

        for(int i = 0; i <= nums.size(); i++) {
            comb[i][0] = comb[i][i] = 1;
            for(int j = 1; j < i; j++)
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
        }

        return (solve(nums) - 1 + mod) % mod;
    }
};