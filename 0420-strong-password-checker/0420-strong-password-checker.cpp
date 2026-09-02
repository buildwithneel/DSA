class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.length();

        bool lower = false;
        bool upper = false;
        bool digit = false;
        for (char c : password) {
            if (c >= 'a' && c <= 'z')   lower = true;
            else if (c >= 'A' && c <= 'Z')  upper = true;
            else if (c >= '0' && c <= '9')  digit = true;
        }
        int missing = 0;
        if (!lower) missing++;
        if (!upper) missing++;
        if (!digit) missing++;
        int replace = 0;
        int one = 0;
        int two = 0;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && password[j] == password[i])
                j++;
            int len = j - i;
            if (len >= 3) {
                replace += len / 3;

                if (len % 3 == 0) one++;
                else if (len % 3 == 1) two++;
                }
            i = j;
            }
        if (n < 6) return max(missing, 6 - n);
        if (n <= 20) return max(missing, replace);
        int deletions = n - 20;
        int remain = deletions;
        int use = min(remain, one);
        replace -= use;
        remain -= use;
        use = min(remain / 2, two);
        replace -= use;
        remain -= use * 2;
        replace -= remain / 3;
        return deletions + max(missing, replace);
    }
};