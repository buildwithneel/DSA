class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = -9223372036854775807LL;
        long long second = -9223372036854775807LL;
        long long third = -9223372036854775807LL;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == first || nums[i] == second || nums[i] == third)
                continue;

            if (nums[i] > first) {
                third = second;
                second = first;
                first = nums[i];
            }
            else if (nums[i] > second) {
                third = second;
                second = nums[i];
            }
            else if (nums[i] > third) {
                third = nums[i];
            }
        }

        if (third == -9223372036854775807LL)
            return first;

        return third;
    }
};