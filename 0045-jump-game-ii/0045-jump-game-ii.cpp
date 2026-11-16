class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, curEnd = 0, farthest = 0;

        for (int i = 0; i < (int)nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            if (i == curEnd) {
                jumps++;
                curEnd = farthest;
            }
        }

        return jumps;
    }
};