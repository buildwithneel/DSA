class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long ans=0;
        int count[31]={0};
        int i,j;
        for (i=0;i<nums.size();i++){
            for(j=0;j<31;j++){
                if((nums[i]>>j)&1)
                count[j]++;
            }
        }
        for(i=0;i<k;i++){
            long long x=0;
            for(j=0;j<31;j++){
                if(count[j]>0){
                    x+=1LL<<j;
                    count[j]--;

                }
            }ans=(ans+x*x)%1000000007;
        }return ans;
    }
};