class Solution {
public:
    bool checkOverlap(int r, int x, int y, int x1, int y1, int x2, int y2) {
        
        int cx = max(x1, min(x, x2));
        int cy = max(y1, min(y, y2));

        int dx = x - cx;
        int dy = y - cy;

        return dx * dx + dy * dy <= r * r;
    }
};