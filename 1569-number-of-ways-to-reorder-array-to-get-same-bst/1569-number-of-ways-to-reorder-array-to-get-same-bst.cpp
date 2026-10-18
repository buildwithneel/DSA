class Solution {
public:
    const int MOD=1000000007;

    long long comb[1001][1001]={};

    int ways(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return 1;

        vector<int> l,r;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[0]) l.push_back(nums[i]);
            else r.push_back(nums[i]);
        }

        return comb[n-1][l.size()]*1LL*ways(l)%MOD*ways(r)%MOD;
    }

    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<=n;i++){
            comb[i][0]=comb[i][i]=1;
            for(int j=1;j<i;j++)
                comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%MOD;
        }
        return (ways(nums)-1+MOD)%MOD;
    }
};