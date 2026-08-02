class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size())
            return findMedianSortedArrays(b, a);

        int m = a.size(), n = b.size();
        int l = 0, r = m;

        while (l <= r) {
            int i = (l + r) / 2;
            int j = (m + n + 1) / 2 - i;

            int al = (i == 0) ? INT_MIN : a[i - 1];
            int ar = (i == m) ? INT_MAX : a[i];
            int bl = (j == 0) ? INT_MIN : b[j - 1];
            int br = (j == n) ? INT_MAX : b[j];

            if (al <= br && bl <= ar) {
                if ((m + n) % 2)
                    return max(al, bl);

                return (max(al, bl) + min(ar, br)) / 2.0;
            }

            if (al > br)
                r = i - 1;
            else
                l = i + 1;
        }

        return 0.0;
    }
};