class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int j,i;
        for(i=0;i<n;i++){
            set<int> s;
            for(j=i;j<n;j++){
                s.insert(nums[j]);
                int x=s.size();
                ans+=x*x;
            }
        }return ans;
    }
};