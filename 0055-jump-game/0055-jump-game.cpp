class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far=0;
        int i;
        for(i=0;i<nums.size();i++){
            if(i>far) return false;
            far=max(far,i+nums[i]);
        }return true;
    }
};