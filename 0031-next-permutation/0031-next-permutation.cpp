class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size=nums.size();
        int pivot=size-2;
        while(pivot>=0 && nums[pivot]>=nums[pivot+1]){
            pivot--;
        }if(pivot>=0){
            int nextgreater=size-1;
            while(nums[nextgreater]<=nums[pivot]){
                nextgreater--;
            }
            swap(nums[pivot],nums[nextgreater]);
        }reverse(nums.begin()+pivot+1,nums.end());
    }
};