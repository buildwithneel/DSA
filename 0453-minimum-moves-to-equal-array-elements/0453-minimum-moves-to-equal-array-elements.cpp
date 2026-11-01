class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int i;
        int mn=*min_element(nums.begin(),nums.end());
        long long moves=0;
        for(i=0;i<n;i++){
          moves+=nums[i]-mn;
        }
        return (int)moves;
    }
};