class Solution {
public:
    bool canAliceWin(int n) {
        int x = 10, turns = 0;

        while (n >= x) {
            n -= x;
            x--;
            turns++;
        }

        return turns % 2 == 1;
    }
};