
/**
 * Forward declaration of guess API.
 * @param num   your guess
 * @return      -1 if num is higher than the picked number
 *               1 if num is lower than the picked number
 *               0 if num is equal to the picked number
 *
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int result = guess(mid);

            if (result == 0) {
                return mid;
            }
            else if (result == -1) {
                // mid is higher than the picked number
                right = mid - 1;
            }
            else {
                // mid is lower than the picked number
                left = mid + 1;
            }
        }

        return -1;
    }
};
