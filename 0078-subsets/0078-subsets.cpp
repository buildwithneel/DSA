class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        int mask,i;
        for(mask=0;mask<(1<<n);mask++){
            vector<int>subset;
            for(i=0;i<n;i++){
                if(mask>>i & 1) subset.push_back(nums[i]);
            }
            res.push_back(subset);
        }return res;
    }
};