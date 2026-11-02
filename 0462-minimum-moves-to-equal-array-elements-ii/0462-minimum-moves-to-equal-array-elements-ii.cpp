class Solution {
public:
    int minMoves2(vector<int>& nums) {
      int n=nums.size();
        nth_element(nums.begin(),nums.begin()+n/2,nums.end());
        int median=nums[n/2];
        int i;
        int moves=0;
        for(i=0;i<n;i++) {
            moves+=abs(nums[i]-median);
        }return moves;
    }
};