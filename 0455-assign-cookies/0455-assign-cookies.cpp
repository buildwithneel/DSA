class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& cookies) {
        sort(greed.begin(), greed.end());
        sort(cookies.begin(), cookies.end());

        int childIndex = 0;
        int cookieIndex = 0;
        int contentChildren = 0;

        while (childIndex < greed.size() && cookieIndex < cookies.size()) {
            if (cookies[cookieIndex] >= greed[childIndex]) {
                contentChildren++;
                childIndex++;
            }cookieIndex++;
        }return contentChildren;
    }
};