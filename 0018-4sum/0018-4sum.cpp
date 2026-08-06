class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& numbers, int target) {
        vector<vector<int>> answer;
        int size = numbers.size();

        sort(numbers.begin(), numbers.end());

        for (int first = 0; first < size - 3; first++) {

            if (first > 0 && numbers[first] == numbers[first - 1])
                continue;

            for (int second = first + 1; second < size - 2; second++) {

                if (second > first + 1 && numbers[second] == numbers[second - 1])
                    continue;

                int left = second + 1;
                int right = size - 1;

                while (left < right) {

                    long long currentSum = (long long)numbers[first] +
                                           numbers[second] +
                                           numbers[left] +
                                           numbers[right];

                    if (currentSum == target) {
                        answer.push_back({
                            numbers[first],
                            numbers[second],
                            numbers[left],
                            numbers[right]
                        });

                        left++;
                        right--;

                        while (left < right && numbers[left] == numbers[left - 1])
                            left++;

                        while (left < right && numbers[right] == numbers[right + 1])
                            right--;
                    }
                    else if (currentSum < target) {
                        left++;
                    }
                    else {
                        right--;
                    }
                }
            }
        }

        return answer;
    }
};