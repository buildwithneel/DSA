class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total=0;
        int i;
        for(i=0;i<nums.size();i++){
            total+=nums[i];
        }int left=0;
        for(i=0;i<nums.size();i++){
        if(left==total-left-nums[i]) return i;
        left+=nums[i];
        }return -1;
    }
};