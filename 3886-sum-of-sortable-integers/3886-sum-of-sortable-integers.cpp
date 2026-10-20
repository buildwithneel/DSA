class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<int> pref(n+1,0),suf(n+1,INT_MAX),drop(n,0);
        for(int i=0;i<n;i++)
            pref[i+1]=max(pref[i],nums[i]);
        for(int i=n-1;i>=0;i--)
            suf[i]=min(nums[i],suf[i+1]);
        for(int i=1;i<n;i++)
            drop[i]=drop[i-1]+(nums[i-1]>nums[i]);
        for(int k=1;k<=n;k++){
            if(n%k!=0)
             continue;
        bool ok=true;

        for(int i=0;i<n;i+=k){
                int j=i+k-1;
                int d=drop[j]-drop[i];
                if(nums[j]>nums[i]) d++;

                if(d>1||pref[i]>suf[i]){
                    ok=false;
                    break;
                }
            }

            if(ok) ans+=k;
        }

        return ans;
    }
};