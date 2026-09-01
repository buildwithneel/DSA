class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maximumXor = 0;
        int bitMask = 0;

        for (int bit = 30; bit >= 0; bit--) {
            bitMask |= (1 << bit);

            unordered_set<int> prefixes;

            for (int number : nums) {
                prefixes.insert(number & bitMask);
            }

            int possibleXor = maximumXor | (1 << bit);

            for (int prefix : prefixes) {
                int requiredPrefix = prefix ^ possibleXor;

                if (prefixes.count(requiredPrefix)) {
                    maximumXor = possibleXor;
                    break;
                }
            }
        }

        return maximumXor;
    }
};