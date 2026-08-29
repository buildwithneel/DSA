class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result;
        vector<int> sorted;

        for (int i = nums.size() - 1; i >= 0; i--) {
            int low = 0, high = sorted.size();

            while (low < high) {
                int mid = low + (high - low) / 2;

                if (sorted[mid] < nums[i])
                    low = mid + 1;
                else
                    high = mid;
            }

            result.push_back(low);
            sorted.insert(sorted.begin() + low, nums[i]);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};