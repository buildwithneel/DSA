class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        int i;
        for(i=0;i<k;i++) sum+= nums[i];
        int best=sum;
        for(i=k;i<nums.size();i++){
            sum+=nums[i]-nums[i-k];
            best=max(best,sum);
        }return(double)best/k;
    }
};