class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int i;
        int n=nums.size();
    
        for(i=1;i<n;i++){
            nums[i]=nums[i]+nums[i-1];
        }
        return nums;
    }
};