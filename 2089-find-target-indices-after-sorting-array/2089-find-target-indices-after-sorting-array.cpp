class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
      int i;
      sort(nums.begin(),nums.end());
      vector<int> ans;
        for(i=0;i<nums.size();i++){
            if(nums[i]==target) ans.push_back(i);

        }return ans;
    }
};