class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long>dp(n+1,LLONG_MAX);
        dp[0]=0;
        int i,j;
        
        for(i=0;i<=n;i++){
            for(j=max(0,i-3);j<i;j++){
                dp[i]=min(dp[i],dp[j]+costs[i-1]+(long long)(i-j)*(i-j));
            }
        }return (int)dp[n];
    }
};