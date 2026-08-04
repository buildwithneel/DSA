class Solution {
public:
    int threeSumClosest(vector<int>& numbers, int target) {
        sort(numbers.begin(), numbers.end());

        int closestSum = numbers[0] + numbers[1] + numbers[2];

        for (int firstIndex = 0; firstIndex < numbers.size() - 2; firstIndex++) {

            int leftIndex = firstIndex + 1;
            int rightIndex = numbers.size() - 1;

            while (leftIndex < rightIndex) {

                int currentSum = numbers[firstIndex] +
                                 numbers[leftIndex] +
                                 numbers[rightIndex];

                if (abs(target - currentSum) < abs(target - closestSum)) {
                    closestSum = currentSum;
                }

                if (currentSum < target) {
                    leftIndex++;
                }
                else if (currentSum > target) {
                    rightIndex--;
                }
                else {
                    return currentSum;
                }
            }
        }

        return closestSum;
    }
};