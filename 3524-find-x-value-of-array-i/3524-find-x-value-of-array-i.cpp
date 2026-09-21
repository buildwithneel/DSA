class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        long long dp[5]={},ans[5]={};
        for(int x:nums){
            x%=k;
            long long cur[5]={};
            cur[x]=1;
            for(int i=0;i<k;i++)
                cur[i*x%k]+=dp[i];
            for(int i=0;i<k;i++)
                ans[i]+=cur[i];
            for(int i=0;i<k;i++)
                dp[i]=cur[i];
        }
        return vector<long long>(ans,ans+k);
    }
};