class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ans.clear();
        solve(nums,0);
        return ans;
    }
    void solve(vector<int>& nums,int i){
        if(i==nums.size()){
            ans.push_back(nums);
            return;

        }
        for(int j=i;j<nums.size();j++){
            bool ok=true;
            for(int k=i;k<j;k++){
                if(nums[k]==nums[j]){
                ok=false;
                break;
            }
        }
        if(!ok) continue;
        swap(nums[i],nums[j]);
        solve(nums,i+1);
        swap(nums[i],nums[j]);
    }
    }
};